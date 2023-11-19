typedef struct Token Token;
Token *tokenize();

typedef struct Node Node;

typedef enum {
    ND_ADD,
    ND_SUB,
    ND_MUL,
    ND_DIV,
    ND_ASSIGN,
    ND_LVAR,
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
    int offset;    // kindがND_LVARの場合のみ使う
};
typedef struct LVar LVar;
struct LVar {
    LVar *next;     //次の変数化NULL
    char *name;     //変数の名前
    int len;        //名前の長さ
    int offset;     //RBPからのオフセット
};
//ローカル変数
extern LVar *locals;

extern Node *code[100];

void program();

void gen(Node *node);

// 現在着目しているトークン
Token *token;

// 入力プログラム
char *user_input;