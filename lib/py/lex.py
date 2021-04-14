w = '{\"name\": \"GSP\", \"age\" : 39 }'
seq = ['{', ' ', 'name', ':', 'GSP', ',', 'age', ':', '39', '}']

BRACE = ['{', '}']
BRACKET = ['[', ']']
SEPARATOR = [',', ':']
NUMBER = '0123456789'
DOUBLE_QUOTE = '\"'
WHITE_SPACE = [' ', '\t', '\n']

def lex(s):
    tokens = []
    while len(s):
        # braces
        token, s = lex_brace(s)
        if token is not None:
            tokens.append(token)

        # brackets
        token, s = lex_bracket(s)
        if token is not None:
            tokens.append(token)

        # separators
        token, s = lex_separator(s)
        if token is not None:
            tokens.append(token)

        # strings
        token, s = lex_string(s)
        if token is not None:
            tokens.append(token)

        # numbers
        token, s = lex_number(s)
        if token is not None:
            tokens.append(token)

        # whitespace
        token, s = lex_whitespace(s)

    return tokens

def lex_brace(s):
    if not s:
        return None, s
    elif s[0] in BRACE:
        return s[0], s[1:]
    else:
        return None, s

def lex_bracket(s):
    if not s:
        return None, s
    elif s[0] in BRACKET:
        return s[0], s[1:]
    else:
        return None, s

def lex_string(s):
    if not s:
        return None, s
    elif s[0] == DOUBLE_QUOTE:
        i = 1
        while (i < len(s)): 
            if (s[i] == DOUBLE_QUOTE):
                return s[1:i], s[i+1:]
            else:
                i += 1

    return None, s

def lex_whitespace(s):
    if not s:
        return None, s
    elif s[0] in WHITE_SPACE:
        return None, s[1:]
    else:
        return None, s

def lex_separator(s):
    if not s:
        return None, s
    elif s[0] in SEPARATOR:
        return s[0], s[1:]
    else:
        return None, s

def lex_number(s):
    i = 0
    while i < len(s) and (s[i] in NUMBER):
        i += 1

    if not i:
        return None, s
    else:
        return s[:i], s[i+1:]

def lex_bool(s):
    pass

def main():
    tokens = lex(w)
    print(tokens)

if __name__ == "__main__":
    main()
