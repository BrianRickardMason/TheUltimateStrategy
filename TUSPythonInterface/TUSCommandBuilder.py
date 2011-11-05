# Name: TUSCommandBuilder.py
# Description: Holds the command builder - the provider of xml formatted commands.
# Author: Marcin Skrobiranda.

import TUSDictionary

from xml.dom.minidom import Document

class CommandBuilderException(Exception):
    """ Exception for handling problems that occurred during the building of a command. """

    def __init__(self):
        """ TODO. """

        pass

class CommandBuilder:
    """ Builds xml commands basing upon the language dictionary. """

    def __init__(self):
        """ Initializes CommandBuilder. """

        pass

    def build(self, a_id_request, a_user_values, a_parameters_values):
        """ Builds a command.

        Requires three arguments:
        a_id_request        - the identifier of the request.
        a_user_values       - the values of the <user> element.
        a_parameters_values - the values of the <parameters> element.

        Returns a human readable xml command.

        """

        # Get the command schema from the dictionary.
        try:
            command_schema = TUSDictionary.COMMAND_SCHEMAS[a_id_request]

            # Create a document.
            command = Document()

            # Create the <request> element.
            request = command.createElement("request")
            command.appendChild(request)
            request.setAttribute("id", repr(command_schema[0]))

            if command_schema[1]:
                if len(command_schema[1]) != len(a_user_values):
                    raise CommandBuilderException()

                user = command.createElement("user")
                request.appendChild(user)

                login = command.createElement("login")
                user.appendChild(login)
                login.setAttribute("value", a_user_values[0])

                password = command.createElement("password")
                user.appendChild(password)
                password.setAttribute("value", a_user_values[1])

            if command_schema[2]:
                if len(command_schema[2]) != len(a_parameters_values):
                    raise CommandBuilderException()

                parameters = command.createElement("parameters")
                request.appendChild(parameters)

                for (name, value) in zip(command_schema[2], a_parameters_values):
                    element = command.createElement(name)
                    parameters.appendChild(element)
                    element.setAttribute("value", value)

            # Return a newly created command in human readable format.
            return command.toprettyxml(indent="    ")

        except:
            raise CommandBuilderException()
