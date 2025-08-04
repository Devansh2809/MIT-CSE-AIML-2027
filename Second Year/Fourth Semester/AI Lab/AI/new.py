import base64

# The encoded string
encoded_string = "N3q8ryccAAQrDS+tIAAAAAAAAABqAAAAAAAAANGqpB7VL3HfX5dq2a0oNrtZRM2Hum9ExZnUSpeMMG2rzSg6lQEEBgABCSAABwsBAAIkBvEHARJTD3GIJuGJqEfIwbSE/71QeN8hIQEAAQAMIBwACAoBra6o3QAABQEZAQAREwBmAGwAYQBnAC4AdAB4AHQAAAAZABQKAQCfS+NlYELbARUGAQAgAAAAAAA="

# Decode the Base64 string
decoded_bytes = base64.b64decode(encoded_string)

# Output the decoded result
print(decoded_bytes.decode('utf-8', errors='ignore'))  # Attempt to decode as UTF-8
