# 📦 Sistema de Estoque de uma Loja de Conveniência

Projeto desenvolvido em C para gerenciar produtos de uma loja de conveniência usando listas encadeadas.

<p align="center">
    <a href="https://github.com/geovane-nves/loja-de-produtos-em-C"><img src="https://img.shields.io/badge/C-C11-00599C?style=for-the-badge&logo=c&logoColor=white" alt="Linguagem C C11"></a>
    <a href="https://github.com/geovane-nves/loja-de-produtos-em-C"><img src="https://img.shields.io/badge/GNU%20Make-build-A42E2B?style=for-the-badge&logo=gnu&logoColor=white" alt="GNU Make"></a>
    <a href="https://github.com/geovane-nves/loja-de-produtos-em-C"><img src="https://img.shields.io/badge/Estruturas-Listas%20encadeadas-2E8B57?style=for-the-badge" alt="Listas encadeadas"></a>
</p>
<p align="center">
    <a href="https://github.com/geovane-nves/loja-de-produtos-em-C"><img src="https://img.shields.io/github/repo-size/geovane-nves/loja-de-produtos-em-C?style=flat-square&logo=github" alt="Tamanho do repositório"></a>
    <a href="https://github.com/geovane-nves/loja-de-produtos-em-C/commits"><img src="https://img.shields.io/github/last-commit/geovane-nves/loja-de-produtos-em-C?style=flat-square&logo=git" alt="Último commit"></a>
    <a href="https://github.com/geovane-nves/loja-de-produtos-em-C/issues"><img src="https://img.shields.io/github/issues/geovane-nves/loja-de-produtos-em-C?style=flat-square&logo=github" alt="Issues abertas"></a>
    <a href="https://github.com/geovane-nves/loja-de-produtos-em-C"><img src="https://img.shields.io/github/languages/count/geovane-nves/loja-de-produtos-em-C?style=flat-square&logo=github" alt="Quantidade de linguagens"></a>
</p>

## 👥 Integrantes

<table>
    <tr>
        <td align="center" width="33%">
            <a href="https://github.com/msantos7gabriel">
                <img src="https://avatars.githubusercontent.com/u/113394709?v=4" width="110px" alt="Gabriel Montalvão Santos"><br>
                <strong>Gabriel Montalvão Santos</strong>
            </a><br><br>
            <a href="https://github.com/msantos7gabriel"><img src="https://img.shields.io/github/followers/msantos7gabriel?label=seguidores&style=flat-square&logo=github" alt="Seguidores de Gabriel"></a><br>
            <a href="https://github.com/msantos7gabriel?tab=repositories"><img src="https://img.shields.io/badge/ver%20reposit%C3%B3rios-GitHub-181717?style=flat-square&logo=github" alt="Repositórios de Gabriel"></a>
        </td>
        <td align="center" width="33%">
            <a href="https://github.com/geovane-nves">
                <img src="https://avatars.githubusercontent.com/u/245179684?v=4" width="110px" alt="Geovane"><br>
                <strong>Geovane</strong>
            </a><br><br>
            <a href="https://github.com/geovane-nves"><img src="https://img.shields.io/github/followers/geovane-nves?label=seguidores&style=flat-square&logo=github" alt="Seguidores de Geovane"></a><br>
            <a href="https://github.com/geovane-nves?tab=repositories"><img src="https://img.shields.io/badge/ver%20reposit%C3%B3rios-GitHub-181717?style=flat-square&logo=github" alt="Repositórios de Geovane"></a>
        </td>
        <td align="center" width="33%">
            <a href="https://github.com/baianoo-cmd">
                <img src="https://avatars.githubusercontent.com/u/143428317?v=4" width="110px" alt="Enzo Dias"><br>
                <strong>Enzo Dias</strong>
            </a><br><br>
            <a href="https://github.com/baianoo-cmd"><img src="https://img.shields.io/github/followers/baianoo-cmd?label=seguidores&style=flat-square&logo=github" alt="Seguidores de Enzo"></a><br>
            <a href="https://github.com/baianoo-cmd?tab=repositories"><img src="https://img.shields.io/badge/ver%20reposit%C3%B3rios-GitHub-181717?style=flat-square&logo=github" alt="Repositórios de Enzo"></a>
        </td>
    </tr>
</table>

<p align="center">
    <a href="https://github.com/msantos7gabriel">@msantos7gabriel</a>
    &nbsp;&bull;&nbsp;
    <a href="https://github.com/geovane-nves">@geovane-nves</a>
    &nbsp;&bull;&nbsp;
    <a href="https://github.com/baianoo-cmd">@baianoo-cmd</a>
</p>

## ✨ Sobre o projeto

O programa possui um menu interativo para organizar produtos em diferentes áreas do estoque:

- **Perecíveis:** lista simplesmente encadeada.
- **Não perecíveis:** lista duplamente encadeada.
- **Promoções:** lista circular simplesmente encadeada.

Cada produto possui ID, nome, quantidade, preço e validade. O ID é gerado automaticamente quando o produto é criado.

### 🌟 Destaques

🧾 Cadastro de produtos com geração automática de ID.
🔗 Utilização de listas simplesmente, duplamente e circularmente encadeadas.
➕ Inserção de produtos no início e no fim das listas.
❌ Remoção de produtos no início, no fim e por ID.
🔎 Busca de produtos por parte do nome.
📊 Contagem e atualização de quantidades.
🔄 Exibição em ordem reversa na lista duplamente encadeada.
🧹 Liberação da memória ao esvaziar as listas.
⚠️ Tratamento de lista vazia, ID inexistente, falha de alocação e opções de menu inválidas.

## 🛠️ Requisitos

- GCC ou outro compilador compatível com C11.
- GNU Make.
- Sistema operacional Linux, macOS ou Windows com uma ferramenta equivalente ao Make.

## 🔨 Compilação

Na raiz do projeto, execute:

```bash
make
```

O `Makefile` compila os arquivos `.c` das pastas do projeto com as opções `-Wall -Wextra -pedantic -std=c11` e gera o executável `meu_programa.out`.

Para remover os arquivos objeto e o executável:

```bash
make clean
```

## ▶️ Execução

Depois da compilação, execute:

```bash
./meu_programa.out
```

O menu principal oferece estas opções:

```text
1. Gerenciar Perecíveis (Simples)
2. Gerenciar Nao Perecíveis (Dupla)
3. Gerenciar Promoções (Circular)
0. Sair
```

Na lista simples, é possível inserir no início ou no fim, remover no início, no fim ou por ID, listar, buscar por parte do nome, atualizar a quantidade, contar produtos e esvaziar a lista.

Na lista circular, estão disponíveis inserção no início ou no fim, remoção no início, no fim ou por ID, listagem, busca por parte do nome, atualização de quantidade e contagem. A opção de esvaziamento aparece na interface da função, mas ainda precisa ser integrada ao submenu circular.

## 🗂️ Organização dos arquivos

```text
.
├── main.c
├── Makefile
├── produto/
│   ├── produto.c
│   └── produto.h
├── simples/
│   ├── simples.c
│   ├── simples.h
│   └── menu/
│       ├── menu_simples.c
│       └── menu_simples.h
├── dupla/
│   ├── dupla.c
│   ├── dupla.h
│   └── menu/
│       ├── menu_dupla.c
│       └── menu_dupla.h
├── circular/
│   ├── circular.c
│   ├── circular.h
│   └── menu/
│       ├── menu_circular.c
│       └── menu_circular.h
└── docs/
    └── trabalho.pdf
```

## 📋 Requisitos descritos em `docs/trabalho.pdf`

O documento do trabalho solicita:

1. Implementar listas simplesmente encadeada, duplamente encadeada e circular simplesmente encadeada em módulos separados.
2. Disponibilizar, para cada lista, inserção no início e no fim.
3. Disponibilizar remoção no início, no fim e por ID.
4. Buscar produtos por substring no nome, exibindo todos os resultados.
5. Atualizar a quantidade de um produto a partir do ID.
6. Exibir os dados dos produtos e contar os elementos da lista.
7. Esvaziar completamente cada lista, liberando a memória alocada.
8. Implementar exibição reversa para a lista duplamente encadeada.
9. Tratar lista vazia, ID inexistente, falha de alocação e opção de menu inválida.
10. Entregar os arquivos `.c`, `.h`, `Makefile` e `README.md` em um arquivo compactado.

## 🧭 Estado atual e pendências

- A lista simplesmente encadeada está implementada para produtos perecíveis.
- A lista duplamente encadeada está implementada para produtos não perecíveis.
- A lista circular está implementada para produtos em promoção.
- O menu principal permite acessar os três tipos de lista.
- A lista duplamente encadeada possui navegação normal e reversa por meio dos ponteiros prox e ant.
- Os módulos das listas estão separados em suas respectivas pastas.
- O projeto utiliza alocação dinâmica de memória para os nós das listas.
- O README.md acompanha a estrutura atual do projeto.