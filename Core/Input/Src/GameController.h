#pragma once
#include <map>

#include <string>
#include <iostream>
#include <GLFW/glfw3.h>

//Author Hasan AL-Baghdadi

/***
 * List of controller buttons for xbox and playstation
 */
enum ControllerButton {
    Xbox_A = 0, PS4_X = 0, PS4_CROSS = 0,
    Xbox_B = 1, PS4_O = 1, PS4_CIRCLE = 1,
    Xbox_X = 2, PS4_SQUARE = 2,
    Xbox_Y = 3, PS4_TRIANGLE = 3,
    Xbox_LB = 4, PS4_L1 = 4,
    Xbox_RB = 5, PS4_R1 = 5,
    Xbox_BACK = 6, PS4_SHARE = 6,
    Xbox_START = 7, PS4_START = 7,
    Xbox_LEFT_STICK = 8, PS4_L3 = 8,
    Xbox_RIGHT_STICK = 9, PS4_R3 = 9,
    Xbox_UP = 10, PS4_UP= 10,
    Xbox_LEFT = 11, PS4_LEFT = 11,
    Xbox_RIGHT = 12, PS4_RIGHT = 12,
    Xbox_DOWN = 13, PS4_DOWN =13,
    //Please avoid using these buttons, they do not exist on
    //The Xbox Controller
    PS4_HOME = 14, Xbox_MAX = 14,
    PS4_PAD = 15,
    PS4_L2_B = 16,
    PS4_R2_B = 17,
    PS4_MAX = 18
};


/***
 * List of controller axis for xbox and playstation
 */
enum Axis {
    X_LEFT = 0,
    Y_LEFT = 1,
    X_RIGHT = 2,
    Y_RIGHT = 3,
    Xbox_LT = 4, PS4_L2_A = 5,
    Xbox_RT = 5, PS4_R2_A = 5
};


/***
 * A game controller function for PC
 */
class GameController {
public:


    /***
     * A constructor for a controller that takes in an Id.
     */
    GameController(int);
    /***
     * Returns the name of a controller TODO: research what an name is.
     */
    std::string GetName();
    /***
     * Default Destructor.
     */
    ~GameController();

    /***
     * Returns the controller ID.
     */
    int getControllerId();
    /***
     * Get the state of a button.
     */
    bool getButtonState(ControllerButton);

    /***
     * Set the state of a button.
     */
    void SetKeyStates();
    /***
     * Get the state of an axis.
     */
    float GetAxisState(Axis);

    /***
     * Disconnect a controller.
     */
    void UnbindController();

    /***
     * Returns true if a controller is connected.
     */
    bool isConnected;

protected:
    std::string m_name; /*The controller name, TODO: Research*/
    int m_controllerId; /*controller Id*/

    void mapXb360(); /*TODO: research*/
    void mapPS4(); /*TODO: Research*/

    void insertButtons(ControllerButton, int); /*TODO: Research*/
    void insertAxis(Axis, int); /*TODO: Research*/

    std::map<ControllerButton, int> m_buttonsMap; /*TODO: Research*/
    std::map<int, bool> m_buttonStates; /*A list of button states*/
    std::map<int, float> m_axesStates; /*A list of axis states*/
    std::map<Axis, int> m_axisMap; /*TODO: Research*/
};