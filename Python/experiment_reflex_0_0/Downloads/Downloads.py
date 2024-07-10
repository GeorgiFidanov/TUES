"""Welcome to Reflex!."""

from Downloads import styles

# Import all the pages.
from Downloads.pages import *

import reflex as rx


class State(rx.State):
    """Define empty state to allow access to rx.State.router."""


# Create the app.
app = rx.App(component_styles=styles.component_styles)