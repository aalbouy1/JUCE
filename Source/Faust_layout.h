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

#ifndef FAUST_LAYOUT_H
#define FAUST_LAYOUT_H

#include "../JuceLibraryCode/JuceHeader.h"

#include "juceFlexBox.h"
#include "Faust_tabs.h"

#include "faust/gui/GUI.h"

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define kKnobWidth 70
#define kKnobHeight 70

#define kVSliderWidth 110
#define kVSliderHeight 250

#define kHSliderWidth 350
#define kHSliderHeight 100

#define kButtonWidth 100
#define kButtonHeight 50

#define kCheckButtonWidth 50
#define kCheckButtonHeight 50

#define kNumEntryWidth 100
#define kNumEntryHeight 50

#define kVBargraphWidth 30
#define kVBargraphHeight 100

#define kHBargraphWidth 110
#define kHBargraphHeight 30

/*
 #define kHorizontalSpace 20
 #define kVerticalSpace 40
 */

#define kHorizontalSpace 0
#define kVerticalSpace 0

#define kHorizontalBorder 50
#define kVerticalBorder 50


struct Faust_layout: public GUI, public Component
{
    Faust_layout()
    {
        i = 0;
        j = 0;
        tabLayout = false;
        tabCount = 0;
        
        /*curUI = new JuceUI();
         curUI->setDirection(FlexBox::Direction::row);
         curUI->addItem(this, Colours::green, nullptr, kVSliderWidth, kVSliderHeight, 50, 0, 100, 1, "Label", "Bloc", 0, 1, 1);*/
    }
    
    virtual ~Faust_layout() override{
        
}
    
    virtual void openTabBox(const char* label){
        tabLayout = true;
        tabName = String(label);
        std::cout<<"openTabBox, j = "<<j<<", tabCount = "<<tabCount<<std::endl;
    }
    virtual void openHorizontalBox(const char* label){
        if(j==0 && !tabLayout) {
            verticalLayout = false;
            curUI = new JuceUI();
            curUI->setDirection(FlexBox::Direction::column);
        }
        else if (j == 0 && tabLayout){
            verticalLayout = false;
            curUI = new JuceUI();
            curUI->setDirection(FlexBox::Direction::column);
            tabName = String(label);
        }
        if(!tabLayout){
            blocName = String(label);
        }
        j++;
        std::cout<<"openHorizontal, j = "<<j<<std::endl;
    }
    virtual void openVerticalBox(const char* label){
        if(j==0) {
            verticalLayout = true;
            curUI = new JuceUI();
            curUI->setDirection(FlexBox::Direction::row);
            blocName = String(label);
        }
        else if(j == 1 && tabLayout) {
            curUI = new JuceUI();
            curUI->setDirection(FlexBox::Direction::row);
            verticalLayout = true;
            tabName = String(label);
        }
        j++;
        std::cout<<"openVertical, j = "<<j<<std::endl;
    }
    virtual void closeBox(){
        j--;
        if(j == 0 && tabLayout){
            tabs.addTabs(tabName, curUI);
            tabName.clear();
            tabCount++;
            addAndMakeVisible(tabs);
        }
        else if(j == 0 && !tabLayout){
            addAndMakeVisible(curUI);
        }
        std::cout<<"closeBox, j = "<<j<<std::endl;
        blocName.clear();
    }
    
    // -- active widgets
    
    virtual void addButton(const char* label, FAUSTFLOAT* zone)
    {
        itemWidth = kButtonWidth;
        itemHeight = kButtonHeight;
        itemBasis = screenWidth;
        nbButton++;
        boolButton = true;
        
        curUI->addItem(this, Colours::grey, zone, itemWidth, itemHeight, 0, 0, 0, 0, label, blocName, itemBasis, i, 6);
        
        i++;
    }
    virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
    {
        itemWidth = kCheckButtonWidth;
        itemHeight = kCheckButtonHeight;
        itemBasis = screenWidth;
        nbCheckButton++;
        boolCheckButton = true;
        
        curUI->addItem(this, Colours::grey, zone, itemWidth, itemHeight, 0, 0, 0, 0, label, blocName, itemBasis, i, 7);
        
        i++;
    }
    virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        itemWidth = kVSliderWidth;
        itemHeight = kVSliderHeight;
        verticalLayout ? itemBasis = 0 : itemBasis = screenWidth;
        nbVSlider++;
        boolVSlider = true;
        std::cout<<"addVSlider"<<std::endl;
        
        curUI->addItem(this, Colours::grey, zone, itemWidth, itemHeight, init, min, max, step, label, blocName, itemBasis, i, 2);
        
        i++;
    }
    
    virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        itemWidth = kHSliderWidth;
        itemHeight = kHSliderHeight;
        verticalLayout ? itemBasis = screenWidth : itemBasis = 0;
        nbHSlider++;
        boolHSlider = true;
        std::cout<<"addHSlider"<<std::endl;
        
        curUI->addItem(this, Colours::grey, zone, itemWidth, itemHeight, init, min, max, step, label, blocName, itemBasis, i, 1);
        
        i++;
    }
    
    virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        itemWidth = kNumEntryWidth;
        itemHeight = kNumEntryHeight;
        itemBasis = screenWidth;
        nbNumEntry++;
        boolNumEntry = true;
        
        curUI->addItem(this, Colours::grey, zone, itemWidth, itemHeight, init, min, max, step, label, blocName, itemBasis, i, 3);
        
        i++;
    }
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    {
        itemWidth = kHBargraphWidth;
        itemHeight = kHBargraphHeight;
        verticalLayout ? itemBasis = screenWidth : itemBasis = 0;
        nbHBargraph++;
        boolHBargraph = true;
        
        curUI->addItem(this, Colours::grey, zone, itemWidth, itemHeight, 0.0, min, max, 0.0, label, blocName, itemBasis, i, 4);
    }
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    {
        itemWidth = kVBargraphWidth;
        itemHeight = kVBargraphHeight;
        verticalLayout ? itemBasis = 0 : itemBasis = screenWidth;
        nbVBargraph++;
        boolVBargraph = true;
        
        curUI->addItem(this, Colours::grey, zone, itemWidth, itemHeight, 0.0, min, max, 0.0, label, blocName, itemBasis, i, 5);
    }
    
    // -- metadata declrations
    
    virtual void declare(FAUSTFLOAT* zone, const char* key, const char* value)
    {
        //MetaDataUI::declare(zone, key, value);
    }
    
    int getMinimumWidth(){
        if(tabLayout) { return 400; }
        else{
            int nbElem = boolHSlider + boolVSlider + boolButton + boolCheckButton + boolNumEntry + boolHBargraph + boolVBargraph;
            int elemMinSize[nbElem];
            int k = 0;
            if(verticalLayout){
                if(boolHSlider){
                    elemMinSize[k] = kHSliderWidth;
                    k++;
                }
                if(boolVSlider){
                    elemMinSize[k] = nbVSlider * kVSliderWidth;
                    k++;
                }
                if(boolButton){
                    elemMinSize[k] = kButtonWidth;
                    k++;
                }
                if(boolCheckButton){
                    elemMinSize[k] = kCheckButtonWidth;
                    k++;
                }
                if(boolNumEntry){
                    elemMinSize[k] = kNumEntryWidth;
                    k++;
                }
                if(boolHBargraph){
                    elemMinSize[k] = kHBargraphWidth;
                    k++;
                }
                if(boolVBargraph){
                    elemMinSize[k] = nbVBargraph * kVBargraphWidth;
                    k++;
                }
                std::cout<<"MinWidth : "<<*std::max_element(elemMinSize,elemMinSize+nbElem)<<std::endl;
                minWidth = *std::max_element(elemMinSize,elemMinSize+nbElem);
                return *std::max_element(elemMinSize,elemMinSize+nbElem);
            }
            else{
                int sum = 0;
                sum += boolHSlider * kHSliderWidth;
                sum += boolVSlider * nbVSlider * kVSliderWidth;
                sum += boolButton * kButtonWidth;
                sum += boolCheckButton *  kCheckButtonWidth;
                sum += boolNumEntry *  kNumEntryWidth;
                sum += boolHBargraph * kHBargraphWidth;
                sum += boolVBargraph * nbVBargraph * kVBargraphWidth;
                std::cout<<"MinWidth : "<<sum<<std::endl;
                minWidth = sum;
                return sum;
            }
        }
    }
    
    int getMinimumHeight(){
        if(tabLayout) { return 400; }
        else{
            int nbElem = boolHSlider + boolVSlider + boolButton + boolCheckButton + boolNumEntry + boolHBargraph + boolVBargraph;
            int elemMinSize[nbElem];
            int k = 0;
            std::cout<<"HSlider : "<<nbHSlider<<", VSlider : "<<nbVSlider<<", Button  :"<<nbButton<<", CheckButton : "<<nbCheckButton<<", NumEntry : "<<nbNumEntry<<", HBargraph : "<<nbHBargraph<<", VBargraph : "<<nbVBargraph<<std::endl;
            if(verticalLayout){
                int sum = 0;
                sum += boolHSlider * nbHSlider * kHSliderHeight;
                sum += boolVSlider * kVSliderHeight;
                sum += boolButton * nbButton * kButtonHeight;
                sum += boolCheckButton * nbCheckButton * kCheckButtonHeight;
                sum += boolNumEntry * nbNumEntry * kNumEntryHeight;
                sum += boolHBargraph * nbHBargraph * kHBargraphHeight;
                sum += boolVBargraph * kVBargraphHeight;
                std::cout<<"MinHeight : "<<sum<<std::endl;
                minHeight = sum;
                return sum;
            }
            else{
                if(boolHSlider){
                    elemMinSize[k] = kHSliderHeight;
                    k++;
                }
                if(boolVSlider){
                    elemMinSize[k] = nbVSlider * kVSliderHeight;
                    std::cout<<"VSlider "<<nbVSlider<<std::endl;
                    k++;
                }
                if(boolButton){
                    elemMinSize[k] = kButtonHeight;
                    k++;
                }
                if(boolCheckButton){
                    elemMinSize[k] = kCheckButtonHeight;
                    k++;
                }
                if(boolNumEntry){
                    elemMinSize[k] = kNumEntryHeight;
                    k++;
                }
                if(boolHBargraph){
                    elemMinSize[k] = kHBargraphHeight;
                    k++;
                }
                if(boolVBargraph){
                    elemMinSize[k] = nbVBargraph * kVBargraphHeight;
                    std::cout<<"HBargraph "<<nbVBargraph<<std::endl;
                    k++;
                }
                std::cout<<"MinHeight : "<<*std::max_element(elemMinSize,elemMinSize+nbElem)<<std::endl;
                minHeight = *std::max_element(elemMinSize,elemMinSize+nbElem);
                return *std::max_element(elemMinSize,elemMinSize+nbElem);
            }
        }
    }
    
    Rectangle<int> screen = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
    int screenWidth = screen.getWidth();
    int screenHeight = screen.getHeight();
    bool verticalLayout;
    bool tabLayout;
    int tabCount;
    int nbHSlider = 0, nbVSlider = 0, nbButton = 0, nbCheckButton = 0, nbNumEntry = 0, nbHBargraph = 0, nbVBargraph = 0;
    bool boolHSlider = false, boolVSlider = false, boolButton = false, boolCheckButton = false, boolNumEntry = false, boolHBargraph = false, boolVBargraph = false;
    
    int minWidth, minHeight;
    FAUSTFLOAT itemWidth, itemHeight;
    int itemBasis;
    String blocName, tabName;
    
    FlexBox::Direction direction = FlexBox::Direction::row;
    int i, j;
    
    ScopedPointer<JuceUI> curUI;
    Faust_tabs tabs;
    
    void setFlexBoxSize(int w, int h){
        setSize(w, h);
        curUI->JuceUI::setFlexBoxSize(w, h);
    }
    
    void resized() override{
    std::cout<<"Resizing layout..."<<std::endl;
    if(tabLayout) { tabs.setBounds (getLocalBounds()); }
    else { curUI->JuceUI::resized(); }
    }
    
    void paint(Graphics& g) override{
        if(!tabLayout) { curUI->JuceUI::paint(g); }
    }
    };
    
#endif // FAUST_LAYOUT_H
