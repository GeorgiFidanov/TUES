"""Navbar component for the app."""

from Downloads import styles

import reflex as rx

def light_button() -> rx.Component:
    return rx.vstack(
        rx.hstack(
            rx.color_mode_button(
                rx.color_mode_icon(),
                color_scheme="none",
                _dark={"color": "white"},
                _light={"color": "black"},
            ),
            width="100%",
            display="flex",
            justify_content="end",
            padding="0.75rem 4rem"
        ),
    )


def navbar():
 return rx.flex(
     rx.box(
         rx.link(
             rx.image(src='https://avatars.githubusercontent.com/u/80518661?s=400&u=21e09c489129595375eb28dd14c533bae2f8f270&v=4', width='60px'),
             href='/'
         )
     ),
     rx.spacer(),
     light_button(),
     rx.spacer(),
     rx.center(
         rx.menu(
             rx.menu_button('Menu'),
             rx.menu_list(
              rx.menu_item('This is for'),
              rx.menu_item('  future pages')
             )
         ),
     ),
 )

