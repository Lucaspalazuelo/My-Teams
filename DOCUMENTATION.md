# RFC Style Documentation for Available Commands

This document describes the commands available in the chat system. The command syntax is provided along with error or success messages returned by the system.

## Commands

### /help
- Displays a list of available commands.

### /login {username}
- Logs in the user with the provided username.
  - Response: `OK`
  - Error: `INVALID_USERNAME`, `ALREADY_CONNECTED`

### /logout
- Logs out the currently connected user.
  - Response: `OK`
  - Error: `NOT_CONNECTED`

### /users
- Lists all connected users.
  - Response: `OK`
  - Error: `NOT_CONNECTED`

### /user {user_uuid}
- Retrieves information about a specific user by their UUID.
  - Response: `OK`
  - Error: `NOT_CONNECTED`, `INVALID_USER`

### /send {user_uuid} {message_body}
- Sends a message to the specified user by their UUID.
  - Response: `OK`
  - Error: `NOT_CONNECTED`, `INVALID_USER`

### /messages {user_uuid}
- Retrieves messages from the specified user by their UUID.
  - Response: `OK`
  - Error: `NOT_CONNECTED`, `INVALID_USER`

### /subscribe {team_uuid}
- Subscribes the user to a specified team by the team's UUID.
  - Response: `OK`
  - Error: `NOT_CONNECTED`, `INVALID_TEAM`, `INVALID_SUBSCRIBED`

### /subscribed {team_uuid}
- Checks if the user is subscribed to a specified team by the team's UUID.
  - Response: `OK`
  - Error: `NOT_CONNECTED`, `INVALID_TEAM`

### /unsubscribe {team_uuid}
- Unsubscribes the user from a specified team by the team's UUID.
  - Response: `OK`
  - Error: `NOT_CONNECTED`, `INVALID_TEAM`

### /user {team_uuid} {channel_uuid} {thread_uuid}
- Retrieves information about a user within the specified team, channel, and thread by their UUIDs.
  - Response: `OK`
  - Error: `NOT_CONNECTED`, `INVALID_TEAM`, `INVALID_CHANNEL`, `INVALID_THREAD`

### /create {team_name} {team_description}
- Creates a new team with the specified name and description.
  - Response: `OK`
  - Error: `NOT_CONNECTED`, `INVALID_TEAM`

### /create {channel_name} {channel_description}
- Creates a new channel within a team with the specified name and description.
  - Response: `OK`
  - Error: `NOT_CONNECTED`, `INVALID_TEAM`, `INVALID_CHANNEL`

### /create {thread_title} {thread_message}
- Creates a new thread within a channel with the specified title and message.
  - Response: `OK`
  - Error: `NOT_CONNECTED`, `INVALID_TEAM`, `INVALID_CHANNEL`, `INVALID_THREAD`

### /create {comment_body}
- Creates a new comment within a thread with the specified body.
  - Response: `OK`
  - Error: `NOT_CONNECTED`, `INVALID_TEAM`, `INVALID_CHANNEL`, `INVALID_THREAD`

### /list
- Lists all available teams, channels, and threads.
  - Response: `OK`
  - Error: `NOT_CONNECTED`

### /list {list_type}
- Lists a specific type of item (teams, channels, or threads).
  - Response: `OK`
  - Error: `NOT_CONNECTED`, `INVALID_TEAM`, `INVALID_CHANNEL`, `INVALID_THREAD`

### /info
- Retrieves information about the current user.
  - Response: `OK`
  - Error: `NOT_CONNECTED`
