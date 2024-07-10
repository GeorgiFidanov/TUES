"""Sidebar component for the app."""

from Downloads import styles

import reflex as rx

def header():
  return rx.box(
      rx.center(
          rx.box(
              rx.heading("Hi, I'm Georgi Fidanov.", size='xl'),
              rx.heading("Still a student", size='lg'),
              rx.heading("I enjoy making python project for all kinds of purposes", size='lg'),
              rx.heading("and I'm really into boardgames...", size='lg')
          ), 
          rx.spacer(),
          display="flex",
          align_items="center",
          justify_content="center",
          spacing="2rem",
          max_width="100%",
          margin="0 auto"
      ),
  )
