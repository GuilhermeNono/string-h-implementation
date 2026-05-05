# Projetos em C por Nível de Dificuldade

> Uma trilha de projetos técnicos para evoluir do básico ao avançado em C, cobrindo sistemas, redes, algoritmos e baixo nível.

---

## 🟢 Iniciante — Fundamentos Sólidos (5 projetos)

Foco em ponteiros, alocação dinâmica, manipulação de strings e arquivos.

### 1. Implementar a própria `string.h`

Recrie funções como `strlen`, `strcpy`, `strcat`, `strstr`, `strtok` do zero, sem usar a biblioteca padrão.

---
#### 1. Funções de Medição e Cálculo de Endereço

Nesta categoria, o objetivo é percorrer a memória até encontrar o byte de terminação.

- **`strlen` (String Length):** Computa o número de bytes em uma sequência. Tecnicamente, ela subtrai o endereço inicial do endereço do terminador nulo. É o teste básico para sua lógica de incremento de ponteiros.
    
- **`strpbrk` (String Pointer Break):** Busca em uma string a primeira ocorrência de qualquer caractere contido em outra string. É uma operação de busca em conjunto que testa sua eficiência em loops aninhados.
    

#### 2. Funções de Cópia e Movimentação (Data Movement)

Aqui reside o maior perigo de **Buffer Overflow** e corrupção de memória.

- **`strcpy` (String Copy):** Copia os bytes da fonte para o destino, incluindo o nulo. Ela pressupõe que o destino tem espaço suficiente. Se o destino for menor, você sobrescreverá o **Stack Frame** ou o **Heap**, causando comportamento indefinido.
    
- **`strncpy`:** Uma versão "segura" que limita a cópia a $n$ bytes. Entretanto, ela possui uma armadilha de design: se o limite $n$ for atingido antes do nulo, a string resultante **não terá** um terminador nulo, o que é uma vulnerabilidade latente.

#### 3. Funções de Comparação e Ordem Lexicográfica

Essas funções são cruciais para algoritmos de ordenação e busca.

- **`strcmp` (String Compare):** Compara byte a byte até encontrar uma diferença ou o terminador nulo. O retorno é a diferença aritmética entre os dois bytes (baseado na tabela ASCII/UTF-8). Se o retorno for $0$, os conteúdos na memória são idênticos. 

#### 4. Funções de Busca e Tokenização

- **`strchr` (String Character):** Varre a memória em busca da primeira ocorrência de um byte específico. Retorna o endereço exato (ponteiro) daquele byte na memória.
    
- **`strstr` (String String):** Implementa a busca de uma sub-string dentro de outra. É o seu primeiro desafio de complexidade algorítmica ($O(n \times m)$ na versão ingênua).
    
- **`strtok` (String Tokenizer):** Uma função polêmica e tecnicamente complexa. Ela utiliza uma **Static Storage Duration** (variável estática interna) para manter o estado entre chamadas sucessivas, permitindo "quebrar" uma string em partes baseadas em delimitadores.

---
### 2. Lista encadeada genérica

Implemente uma lista duplamente encadeada com `void*` para suportar qualquer tipo de dado. Inclua insert, remove, busca e ordenação (merge sort na lista).

### 3. Calculadora com pilha (Shunting Yard)

Parse e avalie expressões matemáticas em notação infixa usando o algoritmo Shunting Yard, convertendo para RPN e avaliando com uma pilha. Suporte parênteses e precedência de operadores.

### 4. Leitor/escritor de CSV

Leia arquivos CSV com campos entre aspas, quebras de linha escapadas e delimitadores variáveis. Exporte para outro formato (JSON ou TSV). Foco em parsing robusto e tratamento de edge cases.

### 5. Jogo da memória no terminal

Tabuleiro com pares de cartas, entrada do usuário, controle de estado e placar. Foco em organização de código com structs, separação de responsabilidades e uso correto de `ncurses`.

---

## 🟡 Intermediário — Sistemas, Redes e Estruturas (10 projetos)

Foco em syscalls, concorrência, estruturas de dados avançadas e protocolos de rede.

### 6. Shell próprio (`mysh`)

Interprete comandos com:

- Pipes (`cmd1 | cmd2 | cmd3`)
- Redirecionamento (`>`, `<`, `>>`, `2>`)
- Execução em background (`&`) e `wait`
- Variáveis de ambiente e expansão de `~` e `$VAR`
- Builtins: `cd`, `export`, `exit`, `history`

### 7. Alocador de memória (`mymalloc`)

Recrie `malloc`/`free`/`realloc` usando `sbrk` ou `mmap`. Implemente:

- Estratégias: _first-fit_, _best-fit_, _worst-fit_
- Coalescing de blocos livres adjacentes
- Header/footer para metadados de bloco
- Detecção de double-free e heap overflow básico

### 8. Pool de threads

Crie um pool de workers com fila de tarefas. Use `pthread`, `mutex` e `condition variables`. Suporte cancelamento gracioso, reuso de threads e monitoramento de carga.

### 9. Servidor HTTP/1.1

Aceite conexões TCP e implemente:

- Parsing de requisições GET/POST
- Serving de arquivos estáticos com MIME types corretos
- Keep-alive, timeout de conexão e cabeçalhos obrigatórios
- Respostas com status codes (200, 404, 405, 500)
- Multiplexação de conexões com `select` ou `poll`

### 10. Compressor com Huffman

Leia um arquivo, construa a árvore de frequências, gere os códigos binários e escreva o arquivo comprimido com o cabeçalho necessário para descompressão fiel. Suporte arquivos arbitrários (não só texto).

### 11. Banco de dados key-value em memória

Inspire-se no Redis:

- Hash table com encadeamento e rehashing dinâmico
- Protocolo de texto simples via TCP (RESP-like)
- Comandos: `SET`, `GET`, `DEL`, `TTL`, `KEYS`, `EXPIRE`
- Persistência básica por dump binário ou append-only log

### 12. `grep` próprio com regex básica

Implemente correspondência de padrões com suporte a `.`, `*`, `+`, `?`, `^`, `$` e classes de caracteres `[abc]` usando NFA. Suporte múltiplos arquivos, `-n` (número de linha) e `-i` (case insensitive).

### 13. Cliente/Servidor de chat TCP

Implemente um chat multi-usuário:

- Servidor multiplexado com `epoll` (Linux) ou `kqueue` (BSD/macOS)
- Protocolo de mensagens com framing (length-prefix)
- Salas de chat, broadcast e mensagens privadas
- Autenticação simples por nickname e detecção de desconexão

### 14. Traceroute próprio

Use raw sockets e ICMP para rastrear a rota de pacotes até um destino:

- Envio de pacotes UDP/ICMP com TTL incremental
- Recebimento e parsing de respostas ICMP Time Exceeded
- Resolução reversa de DNS dos hops
- Exibição de latência por salto (3 probes por hop)

### 15. Implementação do protocolo DNS (resolver)

Construa um resolver DNS do zero:

- Serialização e parsing do formato binário de mensagens DNS (RFC 1035)
- Suporte a registros A, AAAA, MX, CNAME e TXT
- Resolução recursiva partindo dos root servers
- Cache com TTL e suporte a múltiplos servidores upstream

---

## 🔴 Avançado — Baixo Nível, Redes e Compiladores (15 projetos)

Foco em arquitetura, parsing, emulação, ptrace, segurança e otimização.

### 16. Mini sistema de arquivos

Implemente um FS sobre um arquivo binário com:

- Inodes, blocos de dados e bitmap de alocação
- Suporte a diretórios, criação/leitura/deleção de arquivos e hard links
- Journaling básico para consistência após crash
- Montagem via FUSE para integração real com o SO

### 17. Emulador CHIP-8

Emule a CPU CHIP-8 completa:

- Fetch / Decode / Execute de 35 opcodes
- Registradores, memória (4KB), stack, timers de delay e som
- Display 64×32 com SDL2, suporte a ROMs reais e modo de debug step-by-step

### 18. Debugger com `ptrace`

Use a syscall `ptrace` do Linux para:

- Anexar a um processo em execução ou lançar sob controle
- Inspecionar e modificar registradores e memória arbitrária
- Definir breakpoints por endereço (substituição por `INT3`)
- Single-step, watchpoints e backtrace de chamadas com DWARF

### 19. Compilador de uma linguagem simples

Escreva um compilador do zero para uma linguagem com variáveis, if/else, loops e funções:

- **Lexer** — tokenização com suporte a literais, operadores e comentários
- **Parser** — AST via Recursive Descent
- **Semantic analysis** — checagem de tipos e escopos
- **Code gen** — geração de x86-64 assembly ou bytecode para VM própria

### 20. Motor de expressões regulares (NFA/DFA)

Implemente um regex engine completo:

- Parsing da expressão para AST
- Conversão AST → NFA (construção de Thompson)
- Simulação do NFA ou conversão para DFA com subset construction
- Suporte a grupos de captura com backreferences

### 21. Corrotinas / Green Threads

Implemente troca de contexto manual em C puro:

- Manipulação direta de stack com `mmap` e guard pages
- Salvar/restaurar registradores via inline assembly (`x86-64`)
- Scheduler cooperativo com `yield` e preemptivo com `SIGALRM`
- Canal de comunicação entre corrotinas (estilo Go channels)

### 22. `strace` caseiro

Intercepte e exiba syscalls de outro processo via `ptrace`:

- Identifique o número da syscall via tabela gerada do kernel
- Decodifique argumentos (strings, flags, structs como `stat`, `sockaddr`)
- Exiba valor de retorno, erros e duração de cada chamada
- Suporte a processos com múltiplas threads (`PTRACE_SEIZE`)

### 23. Interpretador de Forth

Implemente a linguagem Forth:

- Stack machine com palavras primitivas (`+`, `-`, `DUP`, `DROP`, `SWAP`, `ROT`)
- Dicionário de palavras definidas pelo usuário (`:` e `;`)
- Palavras de controle: `IF/ELSE/THEN`, `DO/LOOP`, `BEGIN/UNTIL`
- REPL interativo, execução de arquivos `.forth` e GC de palavras

### 24. Servidor de proxy reverso HTTP

Implemente um proxy reverso funcional:

- Roteamento de requisições para múltiplos backends por path/header
- Connection pooling para backends upstream
- Suporte a chunked transfer encoding e streaming de resposta
- Health check ativo dos backends e failover automático
- Logging estruturado de requisições (formato Common Log)

### 25. Implementação do TLS 1.3 (parcial)

Implemente partes do handshake TLS 1.3 sobre TCP raw:

- Parsing de registros TLS e mensagens de handshake
- Troca de chaves com ECDHE (X25519) usando libsodium
- Derivação de chaves com HKDF e cifragem com AES-GCM ou ChaCha20-Poly1305
- Verificação de certificados X.509 e chain of trust

### 26. Servidor de DNS autoritativo

Construa um servidor DNS que responde como autoridade de uma zona:

- Parsing e serialização completa do protocolo DNS (UDP + TCP fallback)
- Carregamento de zonas no formato RFC 1035 (zone files)
- Suporte a NXDOMAIN, NOERROR, REFUSED e recursão controlada
- Rate limiting por IP para mitigação de amplification attacks

### 27. Motor de rede assíncrono (event loop)

Implemente um event loop do zero inspirado em libuv:

- Backend com `epoll` (Linux) / `kqueue` (macOS)
- Timers de alta precisão com heap mínimo
- I/O assíncrono para sockets e arquivos (com thread pool para disk I/O)
- API de callbacks e suporte a corrotinas próprias (projeto 21)

### 28. Scanner de rede / Port scanner

Implemente um scanner de portas e serviços:

- TCP connect scan, SYN scan (raw sockets) e UDP scan
- Fingerprinting de serviços por banners e respostas conhecidas
- Varredura paralela com pool de threads controlado
- Saída em formato XML/JSON compatível com Nmap

### 29. Emulador de CPU 6502

Emule o processador MOS 6502 (usado no NES e Apple II):

- Todos os 56 mnemônicos e 13 modos de endereçamento
- Flags de status, stack, IRQ e NMI
- Integração com mapper de memória para rodar ROMs reais do NES
- Modo de debug com disassembler embutido

### 30. Garbage Collector — Mark and Sweep

Implemente um GC em C para gerenciar objetos de uma VM ou linguagem:

- Rastreamento de raízes (stack, globais, registradores)
- Mark phase com DFS iterativo (sem recursão para evitar stack overflow)
- Sweep phase com coalescing e retorno de memória ao sistema
- Suporte a objetos com referências cíclicas e finalizadores

---

## 🗺️ Trilhas Recomendadas

### Trilha de Sistemas

```
Shell (6) → Alocador de memória (7) → Sistema de arquivos (16) → Debugger (18) → strace (22)
```

### Trilha de Redes

```
Servidor HTTP (9) → Chat TCP (13) → Traceroute (14) → DNS resolver (15) → Proxy reverso (24) → DNS autoritativo (26)
```

### Trilha de Segurança

```
Traceroute (14) → Port scanner (28) → strace (22) → TLS 1.3 (25) → Debugger (18)
```

### Trilha de Linguagens

```
Calculadora com pilha (3) → grep com regex (12) → Motor NFA/DFA (20) → Compilador (19) → Forth (23) → GC (30)
```

### Trilha de Emulação

```
string.h (1) → Pool de threads (8) → CHIP-8 (17) → Green Threads (21) → 6502 (29)
```

---

## 📚 Referências Úteis

| Recurso                                      | Relevância                          |
| -------------------------------------------- | ----------------------------------- |
| The Linux Programming Interface (Kerrisk)    | Syscalls, processos, redes, IPC     |
| Crafting Interpreters (Nystrom)              | Compiladores e interpretadores      |
| Computer Systems: A Programmer's Perspective | CS:APP — fundamentos de baixo nível |
| Beej's Guide to Network Programming          | Sockets, TCP/UDP, raw sockets       |
| RFC 1035                                     | Protocolo DNS                       |
| RFC 9110 + RFC 9112                          | HTTP/1.1 semântica e sintaxe        |
| RFC 8446                                     | TLS 1.3                             |
| Writing a CHIP-8 Emulator (Cowgod)           | Emulação de CPU                     |
| libuv source code                            | Referência para event loops         |

---

> 💡 **Dica geral:** prefira implementar do zero antes de consultar referências. Errar e depurar com `gdb` e `valgrind` é onde o aprendizado real acontece.