import re


# noinspection PyPep8Naming
def editMessage(message, pattern):
    matches = re.findall(pattern, message)
    count = len(matches)

    indexes = []
    editedMessage = ""

    for match in re.finditer(pattern, message):
        indexes.append(match.start())

    for i in range(len(message)):
        if i in indexes:
            editedMessage += "@"
        else:
            editedMessage += message[i]

    return [str(editedMessage), str(count)]


pattern = "[.?!][ ]*[A-Z]"
