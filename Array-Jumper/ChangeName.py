import os
import re

def replace_words_in_file(file_path):
    # Read the file
    with open(file_path, 'r', encoding='utf-8') as file:
        content = file.read()

    # Replace the words
    new_content = re.sub(r'Handler', 'Service', content)
    new_content = re.sub(r'_handler', '_service', new_content)

    # Only write to the file if there were changes
    if new_content != content:
        with open(file_path, 'w', encoding='utf-8') as file:
            file.write(new_content)
        return 1, new_content.count('Service') + new_content.count('_service')  # Return a count of the changes made
    return 0, 0

def process_directory(base_path, directories):
    files_changed = 0
    total_replacements = 0
    for directory in directories:
        dir_path = os.path.join(base_path, directory)
        if not os.path.exists(dir_path):
            print(f"Directory does not exist: {dir_path}")
            continue
        for root, dirs, files in os.walk(dir_path):
            for file in files:
                if file.endswith('.h') or file.endswith('.cpp'):
                    file_path = os.path.join(root, file)
                    file_changes, replacements = replace_words_in_file(file_path)
                    files_changed += file_changes
                    total_replacements += replacements
                    if file_changes:
                        print(f"Replacements made in file: {file_path}")
    return files_changed, total_replacements

# Set the base path to the location of the 'header' and 'source' directories
base_path = r'D:\Pitara\Work\Outscal\Array Jumper\Project Files\Array-Jumper\Array-Jumper'

# Directories to search within
directories_to_search = ['header', 'source']

# Process the directories and replace the words
files_changed, total_replacements = process_directory(base_path, directories_to_search)

# Print out the results
print(f"Total .h and .cpp files changed: {files_changed}")
print(f"Total replacements made: {total_replacements}")