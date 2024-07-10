

app = Flask(__name__)

@app.route('/')
def index():
    return redirect(url_for('api'))


if __name__ == '__main__':
    
    
    app.add_page(index)
    app.add_page(api)
    app.compile()


def index() -> rx.Component:
    """The home page.

    Returns:
        The UI for the home page.
    """
    with open("README.md", encoding="utf-8") as readme:
        content = readme.read()
    return rx.markdown(content, component_map=styles.markdown_style)




"""The home page of the app."""

from Downloads import styles
from Downloads.templates import template
from flask import redirect, url_for
import reflex as rx


@template(route="/", title="Home", image="/github.svg")
def index():
    return redirect(url_for('api'))



