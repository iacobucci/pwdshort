# pwdShort

![Alt text](./screenshot.png?raw=true)

My directory shortener for bash and zsh prompts inspired by [jonathonball's](https://github.com/jonathonball/pwd-shorten), that aims to be much faster on CPU cycles, because it is a compiled binary, nonetheless configurable!

## Requirements
- g++, or any compiler really

## Compilation
- `make` this will generate a `pwdshort` executable in `~/.local/bin` which you can reference in your shell of choi

## Usage
You can reference the executable in your shell rc file like so:

## Bash
- add $(~/.local/binpwdshort) to your PS1

## Zsh (this is my prompt!)
- `PROMPT=' %B%F{green}%n%f%b@%B%F{blue}$(hostname | cut -c -5)%f%b:%F{yellow}%B$(pwdshort)%b%f%# '`
- (i keep my `~/.local/bin` in the eviroment PATH)

## Example Output
The directory path in your prompt will be shortened:

    /very-long-directory-name/other-long-one/current_dir

becomes

    /ver+/oth+/current_dir

Home directories will be changed out as well:

    /home/user/example/directory

becomes

    ~/exa+/directory

Dotfiles directories can be treated differently:

    /home/user/.config/zsh

becomes

    ~/.con+/zsh

## Configuration
Despite my attempt to make this simple executable fast, it is still configurable through #define directives in main.c, you can change those to tweak the prompt as you like!

### Config Values

#### `MAXCHAR`
How much of the original subdirectory name to keep
- default: `4`

#### `HOMESIGN`
The home symbol which will replace the home path
- default `~`

#### `TRAILSIGN`
Symbol used to indicate that a directory name has been shortened.
- default `+`

#### `SEPARATOR`
If you want to get fancy with custom separator symbols :P
- default `/`

#### `DOTFILES`
If you want to display one more character of directories that start with a dot
- by default `true`

### Example Configuration

```
#define MAXCHAR 4
#define SEPARATOR '/'
#define HOMESIGN '~'
#define TRAILINGSIGN '+'
#define DOTFILES true
```

enjoy this! 
