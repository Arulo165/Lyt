#ifndef NW_CTRL_ANIMBUTTON_H_
#define NW_CTRL_ANIMBUTTON_H_
#include <ctrl/ctrl_ButtonBase.h>
#include <nw/ut/ut_LinkList.h>
#include <nw/lyt/lyt_Animator.h>
#include <nw/lyt/lyt_Pane.h>

namespace nw { namespace ctrl {

class AnimButton : public ButtonBase
{
private:
    ut::LinkListNode    m_Link;
    void*               m_StateChangeCallback;
    void*               m_StateChangeCallbackParam;
    lyt::Animator*      m_OnOffAnimator;
    lyt::Animator*      m_DownAnimator;
    lyt::Animator*      m_CancelAnimator;
    lyt::Pane*          m_HitPane;
    math::VEC2          m_HitBoxBottomLeft;
    math::VEC2          m_HitBoxBottomRight;
    u32                 m_Tag;
    char*               m_Name;
};
static_assert(sizeof(AnimButton) == 0x58);

} } // namespace nw::ctrl

#endif // NW_CTRL_ANIMBUTTON_H_