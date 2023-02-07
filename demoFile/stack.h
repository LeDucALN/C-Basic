#define Max 50
typedef int Eltype;
typedef Eltype StackType[Max];
int top;

void Initialize(StackType stack);
int empty(StackType stack);
int full(StackType stack);
void push(Eltype el,StackType stack);
Eltype pop(StackType stack);
