#ifndef _GUIPROGRESSBAR_
#define _GUIPROGRESSBAR_

//////////////////////////////////////////////////////////////////////////////////////////
// File:            GUIProgressBar.h
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     GUIProgressBar class
// Project:         GUI Library
// Author(s):       Jason Boettcher
//                  jackal@shplorb.com
//                  www.shplorb.com/~jackal


namespace RTE
{


//////////////////////////////////////////////////////////////////////////////////////////
// Class:           GUIProgressBar
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     A progressbar control class.
// Parent(s):       GUIControl, Panel.
// Class history:   1/15/2004 GUIProgressBar Created.

class GUIProgressBar :
    public GUIControl,
    public GUIPanel
{

//////////////////////////////////////////////////////////////////////////////////////////
// Public member variable, method and friend function declarations

public:

    // Progressbar Notifications
    enum {
        Clicked = 0,
        Changed
    } Notification;


//////////////////////////////////////////////////////////////////////////////////////////
// Constructor:     GUIProgressBar
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Constructor method used to instantiate a GUIProgressBar object in
//                  system memory.
// Arguments:       GUIManager, GUIControlManager.

    GUIProgressBar(GUIManager *Manager, GUIControlManager *ControlManager);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Create
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the control has been created.
// Arguments:       Name, Position.

    void Create(const std::string Name, int X, int Y, int Width = -1, int Height = -1) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Create
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the control has been created.
// Arguments:       Properties.

    void Create(GUIProperties *Props) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Destroy
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the control has been destroyed.
// Arguments:       None.

    void Destroy() override; 


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          ChangeSkin
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the skin has been changed.
// Arguments:       New skin pointer.

    void ChangeSkin(GUISkin *Skin) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Draw
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Draws the panel
// Arguments:       Screen class

    void Draw(GUIScreen *Screen) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:  OnMouseDown
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the mouse goes down on the panel
// Arguments:       Mouse Position, Mouse Buttons, Modifier.

    void OnMouseDown(int X, int Y, int Buttons, int Modifier) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:  OnMouseUp
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the mouse goes up on the panel
// Arguments:       Mouse Position, Mouse Buttons, Modifier.

    void OnMouseUp(int X, int Y, int Buttons, int Modifier) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          OnMouseMove
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the mouse moves (over the panel, or when captured).
// Arguments:       Mouse Position, Mouse Buttons, Modifier.

    void OnMouseMove(int X, int Y, int Buttons, int Modifier) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetPanel
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Returns the panel of the control.
// Arguments:       None.
// Returns:         0 if the control does not have a panel, otherwise the topmost panel.

    GUIPanel * GetPanel() override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetControlID
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Returns a string representing the control's ID
// Arguments:       None.

    static std::string GetControlID()    { return "PROGRESSBAR"; };


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Move
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the control needs to be moved.
// Arguments:       New position.

    void Move(int X, int Y) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          Resize
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Called when the control needs to be resized.
// Arguments:       New size.

    void Resize(int Width, int Height) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetControlRect
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the rectangle of the control.
// Arguments:       Position, Size.

    void GetControlRect(int *X, int *Y, int *Width, int *Height) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          StoreProperties
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the control to store the values into properties.
// Arguments:       None.

    void StoreProperties() override;


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetValue
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets the value.
// Arguments:       Value.

    void SetValue(int Value);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetValue
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the value.
// Arguments:       None.

    int GetValue();


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetMinimum
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets the minimum.
// Arguments:       Minimum.

    void SetMinimum(int Minimum);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetMinimum
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the minimum.
// Arguments:       None.

    int GetMinimum();


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          SetMaximum
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Sets the maximum.
// Arguments:       Maximum.

    void SetMaximum(int Maximum);


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          GetMaximum
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Gets the maximum.
// Arguments:       None.

    int GetMaximum();


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          ApplyProperties
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Applies new properties to the control.
// Arguments:       GUIProperties.

    void ApplyProperties(GUIProperties *Props) override;


//////////////////////////////////////////////////////////////////////////////////////////
// Private member variable and method declarations

private:


//////////////////////////////////////////////////////////////////////////////////////////
// Method:          BuildBitmap
//////////////////////////////////////////////////////////////////////////////////////////
// Description:     Create the progressbar bitmap to draw.
// Arguments:       None.

    void BuildBitmap();


// Members

    GUIBitmap        *m_DrawBitmap;
    GUIBitmap        *m_IndicatorImage;

    int                m_Minimum;
    int                m_Maximum;
    int                m_Value;
    int                m_Spacing;

};


}; // namespace RTE


#endif  //  _GUIPROGRESSBAR_