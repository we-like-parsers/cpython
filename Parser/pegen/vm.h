typedef enum _opcodes {
    OP_NOOP,
    OP_CUT,
    OP_OPTIONAL,
    OP_NAME,
    OP_NUMBER,
    OP_STRING,
    OP_LOOP_ITERATE,
    OP_LOOP_COLLECT,
    OP_LOOP_COLLECT_NONEMPTY,
    OP_LOOP_COLLECT_DELIMITED,
    OP_SAVE_MARK,
    OP_POS_LOOKAHEAD,
    OP_NEG_LOOKAHEAD,
    OP_SUCCESS,
    OP_FAILURE,
    // The rest have an argument
    OP_SOFT_KEYWORD,
    OP_TOKEN,
    OP_RULE,
    OP_RETURN,
} Opcode;

static char *opcode_names[] = {
    "OP_NOOP",
    "OP_CUT",
    "OP_OPTIONAL",
    "OP_NAME",
    "OP_NUMBER",
    "OP_STRING",
    "OP_LOOP_ITERATE",
    "OP_LOOP_COLLECT",
    "OP_LOOP_COLLECT_NONEMPTY",
    "OP_LOOP_COLLECT_DELIMITED",
    "OP_SAVE_MARK",
    "OP_POS_LOOKAHEAD",
    "OP_NEG_LOOKAHEAD",
    "OP_SUCCESS",
    "OP_FAILURE",
    // The rest have an argument
    "OP_SOFT_KEYWORD",
    "OP_TOKEN",
    "OP_RULE",
    "OP_RETURN",
};

#define MAXALTS 10
#define MAXOPCODES 100

typedef struct _rule {
    char *name;
    int type;
    int alts[MAXALTS];
    int opcodes[MAXOPCODES];
} Rule;

#define MAXVALS 10

typedef struct _frame {
    Rule *rule;
    int mark;
    int savemark;
    int ialt;
    int iop;
    int cut;
    int ncollected;
    int capacity;
    int ival;
    void **collection;
    void *vals[MAXVALS];
} Frame;
