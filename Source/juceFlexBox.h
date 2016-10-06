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
#include "CustomLookAndFeel.h"

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


struct JuceUI: public Component, public FlexBox, GUI
{
    JuceUI()
    {
        this->flexWrap        = FlexBox::Wrap::wrap;
        this->justifyContent  = FlexBox::JustifyContent::flexStart;
        this->alignItems      = FlexBox::AlignItems::stretch;
        this->alignContent    = FlexBox::AlignContent::stretch;
        
        //setLookAndFeel(myLookAndFeel);
        
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
        this->performLayout (getFlexBoxBounds());
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
    
    
    void addItem(Colour colour, FAUSTFLOAT* zone, FAUSTFLOAT width, FAUSTFLOAT height, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step, String label, int basis, int order, int choice)
    {
        this->items.add(FlexItem(width, height).withFlex(1, 1, basis));
        auto& flexItem = this->items.getReference(this->items.size() - 1);
        
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
            FlexSlider* panel = new FlexSlider(this, colour, flexItem, zone, width, height, min, max, init, step, label, blocName,/* myLookAndFeel,*/ order, choice);
            flexItem.associatedComponent = panel;
            addAndMakeVisible(panel);
        }
    }
    
    //UI Virtual Functions



    virtual void openTabBox(const char* label){
        
        //direction = FlexBox::Direction::row;
        tabName = String(label);
    }
    virtual void openHorizontalBox(const char* label){
        if(j==0) {
            this->flexDirection = FlexBox::Direction::column;
            verticalLayout = false;
        }
        std::cout<<"openHorizontal, j = "<<j<<std::endl;
        blocName = String(label);
        j++;
    }
    virtual void openVerticalBox(const char* label){
        if(j==0) {
            this->flexDirection = FlexBox::Direction::row;
            verticalLayout = true;
        }
        std::cout<<"openVertical, j = "<<j<<std::endl;
        blocName = String(label);
        j++;
    }
    virtual void closeBox(){
        //direction = FlexBox::Direction::row;
        std::cout<<"closeBox, j = "<<j<<std::endl;
        blocName.clear();
        j--;
    }
    
    // -- active widgets
    
    virtual void addButton(const char* label, FAUSTFLOAT* zone)
    {
        itemWidth = kButtonWidth;
        itemHeight = kButtonHeight;
        itemBasis = screenWidth;
        nbButton++;
        boolButton = true;
        
        addItem(Colours::grey, zone, itemWidth, itemHeight, 0, 0, 0, 0, label, itemBasis, i, 6);
        
        i++;
    }
    virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)
    {
        itemWidth = kCheckButtonWidth;
        itemHeight = kCheckButtonHeight;
        itemBasis = screenWidth;
        nbCheckButton++;
        boolCheckButton = true;
        
        addItem(Colours::grey, zone, itemWidth, itemHeight, 0, 0, 0, 0, label, itemBasis, i, 7);
        
        i++;
    }
    virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        itemWidth = kVSliderWidth;
        itemHeight = kVSliderHeight;
        verticalLayout ? itemBasis = 0 : itemBasis = screenWidth;
        nbVSlider++;
        boolVSlider = true;
        
        addItem(Colours::grey, zone, itemWidth, itemHeight, init, min, max, step, label, itemBasis, i, 2);
        
        i++;
    }
    
    virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        itemWidth = kHSliderWidth;
        itemHeight = kHSliderHeight;
        verticalLayout ? itemBasis = screenWidth : itemBasis = 0;
        nbHSlider++;
        boolHSlider = true;
        
        addItem(Colours::grey, zone, itemWidth, itemHeight, init, min, max, step, label, itemBasis, i, 1);
        
        i++;
    }
    
    virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
    {
        itemWidth = kNumEntryWidth;
        itemHeight = kNumEntryHeight;
        itemBasis = screenWidth;
        nbNumEntry++;
        boolNumEntry = true;
        
        addItem(Colours::grey, zone, itemWidth, itemHeight, init, min, max, step, label, itemBasis, i, 3);
        
        i++;
    }
    
    // -- passive widgets
    
    virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    {
        itemWidth = kHBargraphWidth;
        itemHeight = kHBargraphHeight;
        itemBasis = screenWidth;
        nbHBargraph++;
        boolHBargraph = true;
        
        addItem(Colours::grey, zone, itemWidth, itemHeight, 0.0, min, max, 0.0, label, itemBasis, i, 4);
    }
    virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
    {
        itemWidth = kVBargraphWidth;
        itemHeight = kVBargraphHeight;
        itemBasis = 0;
        nbVBargraph++;
        boolVBargraph = true;
        
        addItem(Colours::grey, zone, itemWidth, itemHeight, 0.0, min, max, 0.0, label, itemBasis, i, 5);
    }
    
    // -- metadata declrations
    
    virtual void declare(FAUSTFLOAT* zone, const char* key, const char* value)
    {
        //MetaDataUI::declare(zone, key, value);
    }

int getMinimumWidth(){
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
        return sum;
    }
}

int getMinimumHeight(){
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
        return *std::max_element(elemMinSize,elemMinSize+nbElem);
    }
}
    // VARIABLES
    
    Rectangle<int> screen = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
    int screenWidth = screen.getWidth();
    int screenHeight = screen.getHeight();
    bool verticalLayout;
    int nbHSlider = 0, nbVSlider = 0, nbButton = 0, nbCheckButton = 0, nbNumEntry = 0, nbHBargraph = 0, nbVBargraph = 0;
    bool boolHSlider = false, boolVSlider = false, boolButton = false, boolCheckButton = false, boolNumEntry = false, boolHBargraph = false, boolVBargraph = false;
    
    //ScopedPointer<CustomLookAndFeel> myLookAndFeel;

    int minWidth, minHeight;
    
    FAUSTFLOAT itemWidth, itemHeight;
    int itemBasis;
    String blocName, tabName;

    //FlexBox::Direction direction = FlexBox::Direction::row;
    int i, j;

    //FlexBox flexBox;
};
    
    
