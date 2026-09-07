#ifndef NW_CTRL_BUTTONBASE_H_
#define NW_CTRL_BUTTONBASE_H_

#include <nw/types.h>

namespace nw { namespace ctrl {

class ButtonBase
{
public:
    virtual void On();

private:
    enum State
    {
        STATE_OFF_IDLE = 0,
        STATE_ON,
        STATE_OFF,
        STATE_ON_IDLE,
        STATE_DOWN,
        STATE_DOWN_IDLE,
        STATE_CANCEL
    };

    enum Action
    {
        ACTION_ON = 0,
        ACTION_OFF,
        ACTION_Down,
        ACTION_Cancel
    };

    struct ActionQueue
    {
        ButtonBase::Action      m_Actions[4];
        u32                     m_ActionNum;
    };
    static_assert(sizeof(ActionQueue) == 0x14);

private:
    ButtonBase::State           m_State;
    u32                         m_Flag; // Original Type: nw::ut::BitFlag32
    ButtonBase::ActionQueue     m_ActionQueue;
};
static_assert(sizeof(ButtonBase) == 0x20);

} } // namespace nw::ctrl

#endif //NW_CTRL_BUTTONBASE_H_