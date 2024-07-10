import reflex as rx

class PortfolioConfig(rx.Config):
    pass

config = PortfolioConfig(
    app_name="portfolio",
    db_url="sqlite:///reflex.db",
    env=rx.Env.DEV,
)