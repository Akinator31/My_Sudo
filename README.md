# My Sudo

A custom implementation of the `sudo` command line utility that reproduces core sudo functionality.

## Description

`my_sudo` allows permitted users to execute commands as another user, by default the superuser (root). The project aims to replicate the essential security and permission management features of the original `sudo` command.

## Features

- Execute commands with root privileges
- User authentication with password verification
- Check user permissions against sudoers file
- Support for following flags:
  - `-h`: Display help message
  - `-u [username]`: Run command as specified user
  - `-g [group]`: Run command as specified group  
  - `-E`: Preserve environment variables
  - `-s`: Run shell

## Building

Build the project using make:

```sh
make
```

Set proper permissions (requires root):

```sh
make perm
```

For development with debug symbols:

```sh
make debug
make perm_debug
```

## Usage

Basic usage:

```sh
./my_sudo [options] command
```

Examples:

```sh
# Execute command as root
./my_sudo command

# Execute command as specific user
./my_sudo -u username command

# Execute command as specific group
./my_sudo -g groupname command

# Preserve environment variables
./my_sudo -E command

# Get help
./my_sudo -h
```

## Testing

Run the test suite:

```sh
make tests_run
```

View test coverage report:

```sh
make show_tests
```

## Security

- Verifies user authentication with password
- Checks permissions against sudoers file
- Sets proper user/group IDs and privileges
- Handles password attempts and access controls
