data_dictionary = { 
    "variable_1": {"type": "string", "description": "Name of the person"}, 
    "variable_2": {"type": "integer", "description": "Age of the person"}, 
    "variable_3": {"type": "float", "description": "Height of the person in meters"} 
} 
 
def add_variable(variable_name, variable_type, description): 
    data_dictionary[variable_name] = {"type": variable_type, "description": description} 
 
def update_variable(variable_name, key, value): 
    if variable_name in data_dictionary: 
        data_dictionary[variable_name][key] = value 
    else: 
        print("Error: Variable not found in data dictionary.") 
 
def delete_variable(variable_name): 
    if variable_name in data_dictionary: 
        del data_dictionary[variable_name] 
    else: 
        print("Error: Variable not found in data dictionary.") 
 
def get_variable_info(variable_name):
    if variable_name in data_dictionary:
        return data_dictionary[variable_name]
    else:
        print("Error: Variable not found in data dictionary.")
        return None


add_variable("variable_4", "boolean", "Is the person a student?")
update_variable("variable_1", "description", "Full name of the person")
delete_variable("variable_2")
print(data_dictionary)
