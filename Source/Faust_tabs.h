//
//  Faust_tabs.h
//  Faust
//
//  Created by Adrien Albouy on 05/10/2016.
//
//

#ifndef Faust_Faust_tabs_h
#define Faust_Faust_tabs_h

#include "../JuceLibraryCode/JuceHeader.h"

class Faust_tabs  : public TabbedComponent
{
public:
    Faust_tabs()
    : TabbedComponent (TabbedButtonBar::TabsAtTop)
    {
        
    }
    
    void addTabs(String label, Component* comp){
        addTab(label, Colours::green, comp, true);
    }
};

#endif