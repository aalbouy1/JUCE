/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_LAYOUTUI_H
#define FAUST_LAYOUTUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include "faust/gui/UI.h"
#include <stack>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

#define kKnobWidth 20
#define kKnobHeight 20

#define kVSliderWidth 50
#define kVSliderHeight 200

#define kHSliderWidth 200
#define kHSliderHeight 20

#define kButtonWidth 50
#define kButtonHeight 20

#define kCheckButtonWidth 10
#define kCheckButtonHeight 10

#define kNumEntryWidth 50
#define kNumEntryHeight 20

#define kVBargraphWidth 20
#define kVBargraphHeight 100

#define kHBargraphWidth 100
#define kHBargraphHeight 20

/*
#define kHorizontalSpace 20
#define kVerticalSpace 40
*/

#define kHorizontalSpace 0
#define kVerticalSpace 0


enum Layout {
    kHorizontalLayout,
    kVerticalLayout,
    kTabLayout,
    kNoLayout
};

struct LayoutComponent {
    
    virtual ~LayoutComponent()
    {}
    
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    
    virtual void setRectangle(int x, int y, int w, int h) = 0;

    virtual int getMinimumWidth() = 0;
    virtual int getMinimumHeight() = 0;

    virtual int getPreferredWidth() = 0;
    virtual int getPreferredHeight() = 0;
    
    virtual void write(std::ostream* stream) = 0;
    
};

struct LayoutRect : public LayoutComponent {
    
    int fX, fY, fW, fH, fMinW, fMinH;
    
    LayoutRect():fX(0), fY(0), fW(0), fH(0), fMinW(0), fMinH(0)
    {}
    LayoutRect(int minw, int minh):fX(0), fY(0), fW(0), fH(0), fMinW(minw), fMinH(minh)
    {}
    
    virtual ~LayoutRect()
    {}
    
    int getWidth() override { return fW; }
    int getHeight() override { return fH; }
    
    void setRectangle(int x, int y, int w, int h) override
    {
        fX = x;
        fY = y;
        fW = w;
        fH = h;
    }
    
    int getMinimumWidth() override { return fMinW; }
    int getMinimumHeight() override { return fMinH; }
    
    int getPreferredWidth() override { return fMinW + kHorizontalSpace/2; }
    int getPreferredHeight() override { return fMinH + kVerticalSpace/2; }
    
    void write(std::ostream* stream) override
    {
        *stream << "fX " << fX << " fY " << fY
        << " fW " << fW << " fH " << fH
        << " fMinW " << fMinW << " fMinH " << fMinH
        << std::endl;
    }
    
};

struct LayoutComponentGroup : public LayoutComponent {
    
    std::vector<LayoutComponent*> fComponents;
    Layout fLayoutType;
    
    LayoutComponentGroup(Layout layout) : fLayoutType(layout)
    {}
    
    virtual ~LayoutComponentGroup()
    {
        for (size_t i = 0; i < fComponents.size(); ++i) {
            delete fComponents[i];
        }
    }
    
    void push(LayoutComponent* component) { fComponents.push_back(component); }
    
    int getWidth() override
    {
        int size = 0;
        for (size_t i = 0; i < fComponents.size(); ++i) {
            size += fComponents[i]->getWidth();
        }
        return size + (fComponents.size() - 1) * kHorizontalSpace;
    }
    
    int getHeight() override
    {
        int size = 0;
        for (size_t i = 0; i < fComponents.size(); ++i) {
            size += fComponents[i]->getHeight();
        }
        return size + (fComponents.size() - 1) * kVerticalSpace;
    }
    
    void setRectangle(int x, int y, int w, int h) override
    {
        int minimum_w = getPreferredWidth();
        int minimum_h = getPreferredHeight();
        
        if (minimum_w > w) {
            std::cout << "setRectangle getPreferredWidth : " << minimum_w << " more than : " << w << std::endl;
        }
        
        if (minimum_h > h) {
            std::cout << "setRectangle getPreferredHeight : " << minimum_h << " more than : " << h << std::endl;
        }
        
        int cur_x = x;
        int cur_y = y;
        float ratio_x = float(w)/float(minimum_w);
        float ratio_y = float(h)/float(minimum_h);
        
        std::cout << "setRectangle ratio_x : " << ratio_x << " ratio_y : " << ratio_y << std::endl;
        
        for (size_t i = 0; i < fComponents.size(); ++i) {
            std::cout << "setRectangle Loop cur_x : " << cur_x << " cur_y : " << cur_y << std::endl;
            std::cout << "setRectangle Loop getPreferredWidth : " << fComponents[i]->getPreferredWidth()
                << " getPreferredHeight : " << fComponents[i]->getPreferredHeight() << std::endl;
            
            /*
            fComponents[i]->setRectangle(cur_x, cur_y, fComponents[i]->getMinimumWidth(), fComponents[i]->getMinimumHeight());
            
            if (fLayoutType == kHorizontalLayout) { cur_x += fComponents[i]->getMinimumWidth() + kHorizontalSpace; }
            if (fLayoutType == kVerticalLayout) { cur_y += fComponents[i]->getMinimumHeight() + kVerticalSpace; }
            */
            /*
             if (fLayoutType == kHorizontalLayout) { cur_x += fComponents[i]->getPreferredWidth() * ratio_x; }
             if (fLayoutType == kVerticalLayout) { cur_y += fComponents[i]->getPreferredHeight() * ratio_y; }
            */
            
            
            if (fLayoutType == kHorizontalLayout) {
                cur_y = h/2 - (fComponents[i]->getPreferredHeight() * ratio_y)/2;
                std::cout << "kHorizontalLayout " << "cur_x : " << cur_x  << " cur_y : " << cur_y << std::endl;
                fComponents[i]->setRectangle(cur_x, cur_y, fComponents[i]->getPreferredWidth() * ratio_x, fComponents[i]->getPreferredHeight() * ratio_y);
                cur_x += (fComponents[i]->getPreferredWidth() + kHorizontalSpace) * ratio_x;
            }
            
            if (fLayoutType == kVerticalLayout) {
                cur_x = w/2 - (fComponents[i]->getPreferredWidth() * ratio_x)/2;
                std::cout << "kVerticalLayout " << "cur_x : " << cur_x  << " cur_y : " << cur_y << std::endl;
                fComponents[i]->setRectangle(cur_x, cur_y, fComponents[i]->getPreferredWidth() * ratio_x, fComponents[i]->getPreferredHeight() * ratio_y);
                cur_y += (fComponents[i]->getPreferredHeight() + kVerticalSpace) * ratio_y;
            }
            
            
            /*
            if (fLayoutType == kHorizontalLayout) {
                std::cout << "kHorizontalLayout " << "cur_x : " << cur_x  << " cur_y : " << cur_y << std::endl;
                fComponents[i]->setRectangle(cur_x, cur_y, fComponents[i]->getPreferredWidth() * ratio_x, fComponents[i]->getPreferredHeight() * ratio_y);
                cur_x += (fComponents[i]->getPreferredWidth() + kHorizontalSpace) * ratio_x;
                //cur_y = h/2 - (fComponents[i]->getPreferredHeight() * ratio_y)/2;
            }
            if (fLayoutType == kVerticalLayout) {
                std::cout << "kVerticalLayout " << "cur_x : " << cur_x  << " cur_y : " << cur_y << std::endl;
                fComponents[i]->setRectangle(cur_x, cur_y, fComponents[i]->getPreferredWidth() * ratio_x, fComponents[i]->getPreferredHeight() * ratio_y);
                //cur_x = w/2 - (fComponents[i]->getPreferredWidth() * ratio_x)/2;
                cur_y += (fComponents[i]->getPreferredHeight() + kVerticalSpace) * ratio_y;
            }
            */
            
        }
    }
    
    int getMinimumWidth() override
    {
        int size = 0;
        
        if (fLayoutType == kHorizontalLayout) {
            for (size_t i = 0; i < fComponents.size(); ++i) {
                size += fComponents[i]->getMinimumWidth();
            }
            return size + (fComponents.size() - 1) * kHorizontalSpace;
        } else {
            for (size_t i = 0; i < fComponents.size(); ++i) {
                size = std::max(size, fComponents[i]->getMinimumWidth());
            }
            return size;
        }
    }
    
    int getMinimumHeight() override
    {
        int size = 0;
        
        if (fLayoutType == kVerticalLayout) {
            for (size_t i = 0; i < fComponents.size(); ++i) {
                size += fComponents[i]->getMinimumHeight();
            }
            return size + (fComponents.size() - 1) * kVerticalSpace;
        } else {
            for (size_t i = 0; i < fComponents.size(); ++i) {
                size = std::max(size, fComponents[i]->getMinimumHeight());
            }
            return size;
        }
    }
    
    int getPreferredWidth() override
    {
        int size = 0;
        
        if (fLayoutType == kHorizontalLayout) {
            for (size_t i = 0; i < fComponents.size(); ++i) {
                size += fComponents[i]->getPreferredWidth();
            }
            return size + (fComponents.size() - 1) * kHorizontalSpace;
        } else {
            for (size_t i = 0; i < fComponents.size(); ++i) {
                size = std::max(size, fComponents[i]->getPreferredWidth());
            }
            return size;
        }
    }
    
    int getPreferredHeight() override
    {
        int size = 0;
        
        if (fLayoutType == kVerticalLayout) {
            for (size_t i = 0; i < fComponents.size(); ++i) {
                size += fComponents[i]->getPreferredHeight();
            }
            return size + (fComponents.size() - 1) * kVerticalSpace;
        } else {
            for (size_t i = 0; i < fComponents.size(); ++i) {
                size = std::max(size, fComponents[i]->getPreferredHeight());
            }
            return size;
        }
    }
    
    void write(std::ostream* stream) override
    {
        for (size_t i = 0; i < fComponents.size(); ++i) {
            fComponents[i]->write(stream);
        }
    }
};

/*******************************************************************************
 * LayoutManagerUI : Faust User Interface
 * This class computes the layout and allow to get a rectangle for each zone.
 ******************************************************************************/

class LayoutManagerUI : public UI
{
    private:
    
        LayoutComponentGroup* fCurLayoutGroup;
        std::stack<LayoutComponentGroup*> fLayoutGroupStack;
    
        void openBox(const char* label, Layout layout)
        {
            LayoutComponentGroup* component = new LayoutComponentGroup(layout);
            if (fCurLayoutGroup) {
                fCurLayoutGroup->push(component);
                fLayoutGroupStack.push(fCurLayoutGroup);
            }
            fCurLayoutGroup = component;
        }
   
    public:

        LayoutManagerUI():fCurLayoutGroup(nullptr)
        {}

        virtual ~LayoutManagerUI() { delete fCurLayoutGroup; }
    
        std::map<FAUSTFLOAT*, LayoutRect*> fZoneLayout;
    
        void setSize(int width, int height)
        {
            assert(fCurLayoutGroup);
            //fCurLayoutGroup->setRectangle(50, 50, width - 50, height - 100);
            fCurLayoutGroup->setRectangle(0, 0, width, height);
        }

        // -- widget's layouts

        virtual void openTabBox(const char* label)
        {
            openBox(label, kTabLayout);
            std::cout << "openTabBox label : " << label << std::endl;
            std::cout << "fZoneLayout size " << fZoneLayout.size() << std::endl;
        }
    
        virtual void openHorizontalBox(const char* label)
        {
            openBox(label, kHorizontalLayout);
            std::cout << "openHorizontalBox label : " << label << std::endl;
            std::cout << "fZoneLayout size " << fZoneLayout.size() << std::endl;
        }
    
        virtual void openVerticalBox(const char* label)
        {
            openBox(label, kVerticalLayout);
            std::cout << "openVerticalBox label : " << label << std::endl;
            std::cout << "fZoneLayout size " << fZoneLayout.size() << std::endl;
        }
    
        virtual void closeBox()
        {
            if (!fLayoutGroupStack.empty()) {
                fCurLayoutGroup = fLayoutGroupStack.top();
                fLayoutGroupStack.pop();
            }
            std::cout << "closeBox" << std::endl;
            std::cout << "fZoneLayout size " << fZoneLayout.size() << std::endl;
        }

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            LayoutRect* rect = new LayoutRect(kButtonWidth, kButtonHeight);
            fCurLayoutGroup->push(rect);
            fZoneLayout[zone] = rect;
            
            std::cout << "addButton label : " << label << " zone " << zone << std::endl;
            std::cout << "fZoneLayout size " << fZoneLayout.size() << std::endl;
        }
    
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            LayoutRect* rect = new LayoutRect(kCheckButtonWidth, kCheckButtonHeight);
            fCurLayoutGroup->push(rect);
            fZoneLayout[zone] = rect;
            
            std::cout << "addCheckButton label : " << label << " zone " << zone << std::endl;
            std::cout << "fZoneLayout size " << fZoneLayout.size() << std::endl;
        }
    
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            LayoutRect* rect = new LayoutRect(kVSliderWidth, kVSliderHeight);
            fCurLayoutGroup->push(rect);
            fZoneLayout[zone] = rect;
            
            std::cout << "addVerticalSlider label : " << label << " zone " << zone << " init : " << init
                    << " min : " << min << " max : " << max << " step : " << step << std::endl;
            std::cout << "fZoneLayout size " << fZoneLayout.size() << std::endl;
        }
    
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            LayoutRect* rect = new LayoutRect(kHSliderWidth, kHSliderHeight);
            fCurLayoutGroup->push(rect);
            fZoneLayout[zone] = rect;
            
            std::cout << "addHorizontalSlider label : " << label << " zone " << zone << " init : " << init
                    << " min : " << min << " max : " << max << " step : " << step << std::endl;
            std::cout << "fZoneLayout size " << fZoneLayout.size() << std::endl;
        }
    
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            LayoutRect* rect = new LayoutRect(kNumEntryWidth, kNumEntryHeight);
            fCurLayoutGroup->push(rect);
            fZoneLayout[zone] = rect;
            
            std::cout << "addNumEntry label : " << label << " zone " << zone << " init : " << init
                << " min : " << min << " max : " << max << " step : " << step << std::endl;
            std::cout << "fZoneLayout size " << fZoneLayout.size() << std::endl;
        }

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            LayoutRect* rect = new LayoutRect(kVBargraphWidth, kVBargraphHeight);
            fCurLayoutGroup->push(rect);
            fZoneLayout[zone] = rect;
            
            std::cout << "addHorizontalBargraph label : " << label << " zone " << zone
                << " min : " << min << " max : " << max << std::endl;
            std::cout << "fZoneLayout size " << fZoneLayout.size() << std::endl;
        }
    
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
        {
            LayoutRect* rect = new LayoutRect(kHBargraphWidth, kHBargraphHeight);
            fCurLayoutGroup->push(rect);
            fZoneLayout[zone] = rect;
            
            std::cout << "addVerticalBargraph label : " << label << " zone " << zone
                << " min : " << min << " max : " << max << std::endl;
            std::cout << "fZoneLayout size " << fZoneLayout.size() << std::endl;
        }

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {
            std::cout << "declare key : " << key << " val : " << val << std::endl;
        }
    
        void write(std::ostream* stream)
        {
            fCurLayoutGroup->write(stream);
        }
    
        LayoutRect* getZoneRect(FAUSTFLOAT* zone)
        {
            assert(fZoneLayout.find(zone) != fZoneLayout.end());
            std::cout << "fZoneLayout size " << fZoneLayout.size() << std::endl;
            fZoneLayout[zone]->write(&std::cout);
            return fZoneLayout[zone];
        }
    
};

#endif // FAUST_LAYOUTUI_H
