import reflex as rx
from random import randint
from github import Github


class AppState(rx.State):
    github_info = []
    projects = []
    random_project = []

    def update_github_info(self, info):
        self.github_info = info

    def update_projects_info(self, info):
        self.projects = info

    def update_random_project_info(self, info):
        self.random_project = info

    def get_github_info(self):
        github = Github("...")
        user = github.get_user()
        repos = user.get_repos()
        info = [[repo.name, repo.git_url] for repo in repos]
        self.update_github_info(info)

    def get_projects(self):
        self.get_github_info()
        headings = [('\n', 'Name: ', info[0], 'Link: ', info[1], '\n') for info in self.github_info]
        self.update_projects_info(headings)

    def get_random_project(self):
        self.get_github_info()
        random_index = randint(0, len(self.github_info) - 1)
        project_name = self.github_info[random_index][0]
        project_link = self.github_info[random_index][1]
        info = [{project_name},'->', {project_link}]
        self.update_random_project_info(info)


def projects():  
   return rx.responsive_grid(
       rx.center(
           rx.box( 
               rx.heading("Do you want to see a random project?", size='lg'),
               rx.button('Random Project', on_click=AppState.get_random_project),
               button_for_random_projects(),
               rx.heading("Or all of mine projects?", size='lg'),
               rx.button('Here you can find my projects.', on_click=AppState.get_projects),
               button_for_all_projects()
           )
       )
   )

def button_for_random_projects():
   return rx.box(
       rx.text(AppState.random_project),
   )

def button_for_all_projects():
   return rx.box(
       rx.text(AppState.projects),
   )

def tech_stack():
   return rx.box(
       rx.heading("This is my tech stack", size='lg'),
       rx.text("Python, Java, C/C++, HTML, CSS, Linux, Docker, and more..."),
       rx.text("(keep in mind that I'm still a student, so I'm not a professional developer)"),
   )

