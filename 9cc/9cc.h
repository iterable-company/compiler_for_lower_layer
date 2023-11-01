typedef struct Token Token;
Token *tokenize();

typedef struct Node Node;

typedef enum {
    ND_ADD,
    ND_SUB,
    ND_MUL,
    ND_DIV,
    ND_EQ,
    ND_NEQ,
    ND_GT,
    ND_GTE,
    ND_NUM,
} NodeKind;
struct Node {
    NodeKind kind;
    Node *lhs;
    Node *rhs;
    int val;    // kind が ND_NUMの場合のみ使う
};

Node *expr();

void gen(Node *node);

// 現在着目しているトークン
Token *token;

// 入力プログラム
char *user_input;