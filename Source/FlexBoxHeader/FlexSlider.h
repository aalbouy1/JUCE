//
//  FlexSlider.h
//  Faust
//
//  Created by Adrien Albouy on 23/09/2016.
//
//

#ifndef Faust_FlexSlider_h
#define Faust_FlexSlider_h

#include "faust/gui/GUI.h"
#include "faust/gui/ValueConverter.h"

struct FlexSlider   : public juce::Component, uiItem,
private juce::Slider::Listener
{
    
    FlexSlider(GUI* box, juce::Colour col, FlexItem& item, FAUSTFLOAT* zone, FAUSTFLOAT w, FAUSTFLOAT h, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT cur, FAUSTFLOAT step, const char* label, int order, int choice) : flexItem(item), name(label), colour(col), uiItem(box, zone), width(w), height(h)
    {
        x = 10;
        y = 10;
        switch(choice){
            case 1:
                x += 40;
                style = Slider::SliderStyle::LinearHorizontal;
                horizontal = true;
                break;
            case 2:
                style = Slider::SliderStyle::LinearVertical;
                horizontal = false;
                break;
            case 3:
                slider.setIncDecButtonsMode(Slider::incDecButtonsDraggable_AutoDirection);
                style = Slider::SliderStyle::IncDecButtons;
                horizontal = true;
                break;
            case 4:
                style = Slider::SliderStyle::LinearBar;
                horizontal = true;
                break;
            case 5:
                style = Slider::SliderStyle::LinearBarVertical;
                horizontal = false;
                break;
            default:
                break;
        }
        
        setupSlider(slider, {x, y, width, height}, min, max, cur, step, style);
        addLabelToSlider(label, slider, horizontal);
        
        flexItem.order     = order;
        flexItem.alignSelf = FlexItem::AlignSelf::stretch;
    }
    
    void addLabelToSlider (const String& name, Slider& target, bool horizontal)
    {
        auto label = new Label (name, name);
        label->attachToComponent(&target, horizontal);
        sliderLabel.add (label);
        addAndMakeVisible (label);
    }
    
    void setupSlider(Slider& slider, Rectangle<int> rect, double min, double max, double init, float step, Slider::SliderStyle style){
        slider.setBounds(rect);
        slider.setRange(min, max, step);
        slider.setValue(init);
        slider.addListener(this);
        slider.setSliderStyle(style);
        
        addAndMakeVisible(slider);
    }
    
    void sliderValueChanged (Slider* slider) override
    {
        auto value = slider->getValue();
        
        std::cout<<name<<" : "<<value<<std::endl;
        
        modifyZone(slider->getValue());
        
        if(auto parent = getParentComponent()) { parent->resized(); }
    }
    
    void paint (Graphics& g) override
    {
        auto r = getLocalBounds();
        
        g.setColour (colour);
        g.fillRect (r);
        
        g.setColour (Colours::white);
        g.drawFittedText ("w: " + String (r.getWidth()) + newLine + "h: " + String (r.getHeight()), r.reduced (4), Justification::bottomRight, 2);
    }

    Rectangle<float> getFlexItemBounds() const
    {
        return getLocalBounds().toFloat();
    }

    void resized() override{
        slider.setBounds(x, y, getFlexItemBounds().getWidth()-x-20, getFlexItemBounds().getHeight()-y-10);
    }

    virtual void reflectZone(){
            FAUSTFLOAT v = *fZone;
            fCache = v;
            //slider.setValue(fConverter->faust2ui(v));
    }

    Slider::SliderStyle style;
    Slider slider;
    Label label;
    const char* name;
    ScopedPointer<ValueConverter> fConverter;
    int x, y, width, height;
    bool horizontal;
    OwnedArray<Label> sliderLabel;
    
    
    FlexItem& flexItem;
    juce::Colour colour;
};
#endif
