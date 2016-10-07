#ifndef Faust_FlexButton_h
#define Faust_FlexButton_h

#include "faust/gui/GUI.h"
#include "faust/gui/ValueConverter.h"

struct FlexButton   : public juce::Component, uiItem,
private juce::Button::Listener
{
    
    FlexButton(GUI* box, juce::Colour col, FlexItem& item, FAUSTFLOAT* zone, FAUSTFLOAT w, FAUSTFLOAT h, String label, int order) :  uiItem(box, zone), name(label), width(w), height(h), flexItem(item), colour(col)
    {
        x = 10;
        y = roundToInt((getFlexItemBounds().getHeight()-height)/2);
        
        button.setButtonText(label);
        button.setBounds(x, y, width, height);
        button.addListener(this);
        
        addAndMakeVisible(button);
        
        flexItem.order      = order;
        flexItem.alignSelf = FlexItem::AlignSelf::stretch;
    }
    
    void buttonClicked (Button* button) override
    {
    }
    
    void buttonStateChanged (Button* button) override
    {
        std::cout<<name<<"State Changed "<<button->isDown()<<std::endl;
        if(button->isDown()) { modifyZone(1.0); }
        else { modifyZone(0.0); }
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

    void resized() override
    {
        y = roundToInt((getFlexItemBounds().getHeight()-height)/2);
        button.setBounds(x, y, getFlexItemBounds().getWidth()-20, height);
    }

    void reflectZone() override
    {
        FAUSTFLOAT v = *fZone;
        fCache = v;
    }

    TextButton button;
    String name;


    int x, y, width, height;

    FlexItem& flexItem;
    juce::Colour colour;
};

#endif
