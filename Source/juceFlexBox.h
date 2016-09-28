/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#include "../JuceLibraryCode/JuceHeader.h"

#include "FlexButton.h"
#include "FlexCheckButton.h"
#include "FlexSlider.h"

#include "MainComponent.h"

#include "faust/gui/GUI.h"

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#define kKnobWidth 70
#define kKnobHeight 70

#define kVSliderWidth 100
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

#define kHBargraphWidth 100
#define kHBargraphHeight 30

/*
 #define kHorizontalSpace 20
 #define kVerticalSpace 40
 */

#define kHorizontalSpace 0
#define kVerticalSpace 0

#define kHorizontalBorder 50
#define kVerticalBorder 50


struct JuceUI: public Component, GUI
{
    JuceUI()
    {
        flexBox.flexDirection   = direction;
        flexBox.flexWrap        = FlexBox::Wrap::wrap;
        flexBox.justifyContent  = FlexBox::JustifyContent::flexStart;
        flexBox.alignItems      = FlexBox::AlignItems::stretch;
        flexBox.alignContent    = FlexBox::AlignContent::stretch;
        
        i = 0;
        j = 0;
    }
    
    ~JuceUI() override
    {
    
    }
    
    void setFlexBoxSize(float width, float height){
        setSize(width, height);
    }
    
    void resized() override
    {
        std::cout<<getLocalBounds().getX()<<"X - Y"<<getLocalBounds().getY()<<std::endl;
        std::cout<<getLocalBounds().getWidth()<<"x"<<getLocalBounds().getHeight()<<std::endl;
        flexBox.performLayout (getFlexBoxBounds());
    }
    
    Rectangle<float> getFlexBoxBounds() const
    {
        return getLocalBounds().toFloat();
    }
    
    void paint (Graphics& g) override
    {
        g.fillAll (Colours::lightgrey);
        
        g.setColour (Colours::darkblue);
        g.fillRect (getFlexBoxBounds());
    }
    
    
    void addItem(Colour colour, FAUSTFLOAT* zone, FAUSTFLOAT width, FAUSTFLOAT height, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step, const char* label, int basis, int order, int choice)
    {
        flexBox.items.add(FlexItem(width, height).withFlex(1, 1, basis));
        auto& flexItem = flexBox.items.getReference(flexBox.items.size() - 1);
        
        // ====================================================================================
        // 1 is HorizontalSlider, 2 is VerticalSlider, 3 is NumEntry, 4 is HorizontalBargraph,
        // 5 is VerticalBargraph, 6 is Button, 7 is CheckButton
        
        
        if(choice == 6){
            FlexButton* panel = new FlexButton(this, colour, flexItem, zone, width, height, label, order);
            flexItem.associatedComponent = panel;
            addAndMakeVisible(panel);
        }
        else if(choice == 7){
            FlexCheckButton* panel = new FlexCheckButton(this, colour, flexItem, zone, width, height, label, order);
            flexItem.associatedComponent = panel;
            addAndMakeVisible(panel);
        }
        else{
            FlexSlider* panel = new FlexSlider(this, colour, flexItem, zone, width, height, min, max, init, step, label, order, choice);
            flexItem.associatedComponent = panel;
            addAndMakeVisible(panel);
        }
    }
    
    //UI Virtual Functions
    
    virtual void openTabBox(const char* label){
        //direction = FlexBox::Direction::row;
    }
    virtual void openHorizontalBox(const char* label){
        if(j==0) { direction = FlexBox::Direction::column; }
        std::cout<<"openHorizontal, j = "<<j<<std::endl;
        j++;
    }
    virtual void openVerticalBox(const char* label){
        if(j==0) { direction = FlexBox::Direction::row; }
        std::cout<<"openVertical, j = "<<j<<std::endl;
        j++;
    }
    virtual void closeBox(){
        //direction = FlexBox::Direction::row;
        std::cout<<"closeBox, j = "<<j<<std::endl;
        j--;
    }
    
    // -- active widgets
    
    virtual void addButton(const char* label, FAUSTFLOAT* zone)
    {
        itemWidth = kButtonWidth;
        itemHeight = kButtonHeight;
        itemBasis = screenWidth;
        
        addItem(Colours::lightblue, zone, itemWidth, itemHeight, 0, 0, 0, 0, label, itemBasis, i, 6);
        
        i++;
    }
    virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
    {
        itemWidth = kCheckButtonWidth;
        itemHeight = kCheckButtonHeight;
        itemBasis = screenWidth;
        
        addItem(Colours::lightblue, zone, itemWidth, itemHeight, 0, 0, 0, 0, label, itemBasis, i, 7);
        
        i++;
    }
    virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        itemWidth = kVSliderWidth;
        itemHeight = kVSliderHeight;
        itemBasis = 0;
        
        addItem(Colours::lightblue, zone, itemWidth, itemHeight, init, min, max, step, label, itemBasis, i, 2);
        
        i++;
    }
    
    virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        itemWidth = kHSliderWidth;
        itemHeight = kHSliderHeight;
        itemBasis = screenWidth;
        
        addItem(Colours::lightblue, zone, itemWidth, itemHeight, init, min, max, step, label, itemBasis, i, 1);
        
        i++;
    }
    
    virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        itemWidth = kNumEntryWidth;
        itemHeight = kNumEntryHeight;
        itemBasis = screenWidth;
        
        addItem(Colours::lightblue, zone, itemWidth, itemHeight, init, min, max, step, label, itemBasis, i, 3);
        
        i++;
    }
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    {
        itemWidth = kHBargraphWidth;
        itemHeight = kHBargraphHeight;
        itemBasis = screenWidth;
        
        addItem(Colours::lightblue, zone, itemWidth, itemHeight, 0.0, min, max, 0.0, label, itemBasis, i, 4);
    }
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    {
        itemWidth = kVBargraphWidth;
        itemHeight = kVBargraphHeight;
        itemBasis = 0;
        
        addItem(Colours::lightblue, zone, itemWidth, itemHeight, 0.0, min, max, 0.0, label, itemBasis, i, 5);
    }
    
    // -- metadata declrations
    
    virtual void declare(FAUSTFLOAT* zone, const char* key, const char* value)
    {
        //MetaDataUI::declare(zone, key, value);
    }

    // VARIABLES
    
    Rectangle<int> screen = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
    int screenWidth = screen.getWidth();
    int screenHeight = screen.getHeight();
    
    FAUSTFLOAT itemWidth, itemHeight;
    int itemBasis;
    
    FlexBox::Direction direction = FlexBox::Direction::row;
    int i, j;

    FlexBox flexBox;
};
    
    
