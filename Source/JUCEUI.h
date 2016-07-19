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

#ifndef  __JuceUI_H__
#define  __JuceUI_H__

#include <map>
#include "faust/gui/GUI.h"
#include "faust/gui/MetaDataUI.h"
#include "faust/gui/ValueConverter.h"
#include "../JuceLibraryCode/JuceHeader.h"

//#include <android/log.h>

/**
 * A push button that controls/reflects the value (O/1) of a zone.
 */
class uiButton : public uiItem, public Button::Listener
{
    private:
    
         Button* fButton;
    
    public:
    
        uiButton (GUI* ui, FAUSTFLOAT* zone, Button* button) : uiItem(ui, zone), fButton(button)
        {
            fButton->addListener(this);
        }
    
        virtual ~uiButton()
        {
            delete fButton;
        }
    
        void reflectZone() override
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            //fButton->setDown(v > 0.0);
        }
    
        /** Called when the button is clicked. */
        void buttonClicked(Button*) override
        {
            std::cout << "buttonClicked " << std::endl;
        }
    
        void buttonStateChanged(Button* button) override
        {
        #if JUCE_ANDROID
            __android_log_print(ANDROID_LOG_ERROR, "Faust", "buttonStateChanged");
        #endif
            std::cout << "buttonStateChanged " << button->isDown() << std::endl;
            modifyZone(float( button->isDown()));
        }
    
};

class uiSlider : public uiItem, public Slider::Listener {
    
    private:
    
        Slider*             fSlider;
        Label*              fLabel;
        FAUSTFLOAT			fCur;
        FAUSTFLOAT			fMin;
        FAUSTFLOAT			fMax;
        FAUSTFLOAT			fStep;
        ValueConverter*		fConverter;
    
    public:
    
        uiSlider(GUI* ui, FAUSTFLOAT* zone, Slider* slider, const char* label,
                 FAUSTFLOAT cur, FAUSTFLOAT lo, FAUSTFLOAT hi, FAUSTFLOAT step,
                 MetaDataUI::Scale scale, LayoutManagerUI* layout)
            : uiItem(ui, zone), fSlider(slider), fCur(cur), fMin(lo), fMax(hi), fStep(step)
        {
            // select appropriate converter according to scale mode
            if (scale == kLog) 			{ fConverter = new LogValueConverter(fMin, fMax, fMin, fMax); }
            else if (scale == kExp) 	{ fConverter = new ExpValueConverter(fMin, fMax, fMin, fMax); }
            else 						{ fConverter = new LinearValueConverter(fMin, fMax, fMin, fMax); }
            
            LayoutRect* rect = layout->getZoneRect(zone);
            slider->setBounds(rect->fX, rect->fY, rect->fW, rect->fH);
            
            fLabel = new Label(String::empty, label);
            fLabel->attachToComponent(slider, false);
         
            fSlider->addListener(this);
            fSlider->setRange(fMin, fMax, fStep);
            fSlider->setValue(fConverter->faust2ui(fCur));
            *fZone = fCur;
        }
        
        virtual ~uiSlider()
        {
            delete fConverter;
            delete fSlider;
            delete fLabel;
        }
    
        void reflectZone() override
        {
            FAUSTFLOAT v = *fZone;
            fCache = v;
            fSlider->setValue(fConverter->faust2ui(v));
        }
    
        void sliderValueChanged(Slider*) override
        {
            printf("fSlider->getValue() %f\n", fSlider->getValue());
            modifyZone(fSlider->getValue());
        }
    
};

class JUCEUI : public GUI, public MetaDataUI {
    
    private:
    
        Component* fParent;
        LayoutManagerUI* fLayout;
        std::map<FAUSTFLOAT*, Component*> fZoneComponentMap;
  
    public:
    
        JUCEUI(Component* component, LayoutManagerUI* layout):fParent(component), fLayout(layout) {}
    
        virtual ~JUCEUI() {}
    
        void resized()
        {
            // Adjust all JUCE widget positions and sizes
            std::map<FAUSTFLOAT*, Component*>::iterator it;
            
            for (it = fZoneComponentMap.begin(); it != fZoneComponentMap.end(); ++it) {
                assert(fLayout->fZoneLayout.find((*it).first) != fLayout->fZoneLayout.end());
                LayoutRect* rect = fLayout->fZoneLayout[(*it).first];
                (*it).second->setBounds(rect->fX, rect->fY, rect->fW, rect->fH);
            }
        }
        
        // -- widget's layouts
        
        virtual void openTabBox(const char* label) {}
        virtual void openHorizontalBox(const char* label) {}
        virtual void openVerticalBox(const char* label) {}
        virtual void closeBox() {}
        
        // -- active widgets
        
        virtual void addButton(const char* label, FAUSTFLOAT* zone)
        {
            TextButton* button = new TextButton(label);
            
            LayoutRect* rect = fLayout->getZoneRect(zone);
            button->setBounds(rect->fX, rect->fY, rect->fW, rect->fH);
            fZoneComponentMap[zone] = button;
            
            uiButton* c = new uiButton(this, zone, button);
            fParent->addAndMakeVisible(button);
        }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            /*
            ToggleButton* button = new ToggleButton("A");
            
            LayoutRect* rect = fLayout->getZoneRect(zone);
            // button->setBounds(rect->fX, rect->fY, rect->fW, rect->fH);
            
            button->setBounds(rect->fX, rect->fY, 50, 50);
            
            fZoneComponentMap[zone] = button;
            
            uiButton* c = new uiButton(this, zone, button);
            
            fParent->addAndMakeVisible(button);
            */
        }
    
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            // TODO
            
            if (isKnob(zone)) {
                addVerticalKnob(label, zone, init, min, max, step);
                return;
            } else if (isRadio(zone)) {
                //addVerticalRadioButtons(label, zone, init, min, max, step, fRadioDescription[zone].c_str());
                return;
            } else if (isMenu(zone)) {
                //addMenu(label, zone, init, min, max, step, fMenuDescription[zone].c_str());
                return;
            }
            
            Slider* slider = new Slider();
            slider->setSliderStyle(Slider::LinearVertical);
            //slider->setSliderStyle(Slider::LinearBarVertical);
            
            slider->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
            fZoneComponentMap[zone] = slider;
            
            uiSlider* c = new uiSlider(this, zone, slider, label, init, min, max, step, getScale(zone), fLayout);
            fParent->addAndMakeVisible(slider);
        }
    
        virtual void addVerticalKnob(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            Slider* slider = new Slider();
            slider->setSliderStyle(Slider::RotaryVerticalDrag);
            //slider->setSliderStyle(Slider::LinearBar);
            
            slider->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
            fZoneComponentMap[zone] = slider;
            
            uiSlider* c = new uiSlider(this, zone, slider, label, init, min, max, step, getScale(zone), fLayout);
            fParent->addAndMakeVisible(slider);
        }
    
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            // TODO
            if (isKnob(zone)) {
                addHorizontalKnob(label, zone, init, min, max, step);
                return;
            } else if (isRadio(zone)) {
                //addVerticalRadioButtons(label, zone, init, min, max, step, fRadioDescription[zone].c_str());
                return;
            } else if (isMenu(zone)) {
                //addMenu(label, zone, init, min, max, step, fMenuDescription[zone].c_str());
                return;
            }
            
            Slider* slider = new Slider();
            slider->setSliderStyle(Slider::LinearHorizontal);
            //slider->setSliderStyle(Slider::LinearBar);
            
            slider->setTextBoxStyle(Slider::TextBoxRight, false, 80, 20);
            fZoneComponentMap[zone] = slider;
            
            uiSlider* c = new uiSlider(this, zone, slider, label, init, min, max, step, getScale(zone), fLayout);
            fParent->addAndMakeVisible(slider);
        }
    
        virtual void addHorizontalKnob(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
        {
            Slider* slider = new Slider();
            slider->setSliderStyle(Slider::RotaryHorizontalDrag);
            //slider->setSliderStyle(Slider::LinearBar);
            
            slider->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
            fZoneComponentMap[zone] = slider;
            
            uiSlider* c = new uiSlider(this, zone, slider, label, init, min, max, step, getScale(zone), fLayout);
            fParent->addAndMakeVisible(slider);
        }
    
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {}
        
        // -- passive widgets
        
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
        
        // -- metadata declarations
        
        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* value)
        {
            MetaDataUI::declare(zone, key, value);
        }
    
};

#endif
