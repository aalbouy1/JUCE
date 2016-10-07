#include "../JuceLibraryCode/JuceHeader.h"

#include "FlexButton.h"
#include "FlexCheckButton.h"
#include "FlexSlider.h"

//#include "CustomLookAndFeel.h"

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

struct JuceUI: public Component, public FlexBox
{
    JuceUI()
    {
        this->flexWrap        = FlexBox::Wrap::wrap;
        this->justifyContent  = FlexBox::JustifyContent::flexStart;
        this->alignItems      = FlexBox::AlignItems::stretch;
        this->alignContent    = FlexBox::AlignContent::stretch;
    }
    
    ~JuceUI(){
        
    }
    
    void setDirection(FlexBox::Direction dir){
        this->flexDirection = dir;
    }
    
    void setFlexBoxSize(float width, float height){
        setSize(width, height);
    }
    
    void resized() override
    {
        Rectangle<float> r = getLocalBounds().toFloat();
        std::cout<<"x = "<<r.getX()<<", y = "<<r.getY()<<std::endl;
        std::cout<<r.getWidth()<<"x"<<r.getHeight()<<std::endl;
        this->performLayout (r);
    }
    
    void paint (Graphics& g) override
    {
        g.fillAll (Colours::lightgrey);
        
        g.setColour (Colours::darkblue);
        g.fillRect (getLocalBounds().toFloat());
    }
    
    
    void addItem(GUI* gui, Colour colour, FAUSTFLOAT* zone, FAUSTFLOAT width, FAUSTFLOAT height, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step, String label, String blocName, int basis, int order, int choice)
    {
        this->items.add(FlexItem(width, height).withFlex(1, 1, basis));
        auto& flexItem = this->items.getReference(this->items.size() - 1);
        
        // ====================================================================================
        // 1 is HorizontalSlider, 2 is VerticalSlider, 3 is NumEntry, 4 is HorizontalBargraph,
        // 5 is VerticalBargraph, 6 is Button, 7 is CheckButton
        
        
        if(choice == 6){
            FlexButton* panel = new FlexButton(gui, colour, flexItem, zone, width, height, label, order);
            flexItem.associatedComponent = panel;
            addAndMakeVisible(panel);
        }
        else if(choice == 7){
            FlexCheckButton* panel = new FlexCheckButton(gui, colour, flexItem, zone, width, height, label, order);
            flexItem.associatedComponent = panel;
            addAndMakeVisible(panel);
        }
        else{
            FlexSlider* panel = new FlexSlider(gui, colour, flexItem, zone, width, height, min, max, init, step, label, blocName,/* myLookAndFeel,*/ order, choice);
            flexItem.associatedComponent = panel;
            addAndMakeVisible(panel);
        }
    }
};
    
    
