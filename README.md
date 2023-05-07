# Quick Sort

O Quick Sort é um método eficiente de organização, apesar de não ser tão constante quanto Heap Sort ou Merge Sort, existem métodos para tentar garantir maior eficiência. 

O Quick Sort é baseado no particionamento, que é um método que consiste em escolher um elemento da lista a ser organizada e tratá-lo como um pivô, que nada mais é do que o elemento que nos guiará durante a organização da lista. A partir do pivô, poderemos verificar todos os números menores ou iguais a ele e jogá-los para esquerda e jogar para direita os que forem maiores.

Existem duas estratégias eficientes de posicionamento, Lomuto e Hoare. 
Estou seguindo um material que aborda Lomuto, por ser um pouco mais simples.

A estratégia Lomuto consiste em colocar todos os itens menores que o pivô em sua frente, e, em seguida, trocar de lugar com o último item menor do que ele, isso significa que o pivô estará logo a frente dos itens menores e estará em seu devido lugar.

Por enquanto, vamos tratar como pivô o primeiro item da lista e seguindo assim, um de cada vez, a cada iteração.

    Antes do particionamento: [3, 8, 7, 10, 0, 23, 2, 1, 77]

    Depois do particionamento: [1, 0, 2, 3, 8, 23, 7, 10, 77]

Processo passo a passo para obter este primeiro resultado

    [3, 8, 7, 10, 0, 23, 2, 1, 77] # início -> pivô = 3
    [3, 0, 7, 10, 8, 23, 2, 1, 77] # 8 e 0 trocam de posição
    [3, 0, 2, 10, 8, 23, 7, 1, 77] # 7 e 2 trocam de posição
    [3, 0, 2, 1, 8, 23, 7, 10, 77] # 10 e 1 trocam de posição
    [1, 0, 2, 3, 8, 23, 7, 10, 77] # 3 e 1 trocam de posição

Por enquanto as coisas continuam bagunçadas, mas o pivô já está em seu devido lugar.

### Pseudocódigo da função que executa o particionamento

    function partition (int[] array, int left, int right) -> int
        int pivot = array[left]
        int i = left
        int j = left + 1
        do
            if (array[j] <= pivot)
                i = i + 1
                swap(array[i], array[j])
            j = j + 1
        while(j <= right)

        swap(array[left], array[i])

        return i

Como está é uma chamada recursiva, deveremos executar o particionamento enquanto a lista não estiver organizada e o que ditará isso é uma comparação entre os valores de left e right

O método QuickSort entenderá o valor de i como o índice atual do pivô e usará esse valor como base para entender quais os valores que estão à esquerda e quais os valores que estão à direita para fazer as respectivas chamadas

    int pivot_index = partition(array, left, right)

Para a chamada de Quick Sort que resolverá o particionamento à esquerda usaremos left para definir o novo pivô e ponto de partida da função partition e pivot_index - 1 para definir o índice final da lista

    quickSort(array, left, pivot_index - 1)

Para a chamada de Quick Sort que resolverá o particionamento à direita usaremos o índice do pivô + 1 para definir o novo pivô e ponto de partida da função partition e right para definir o índice final da lista

    quickSort(array, pivot_index + 1, right)

### Pseudocódigo da função QuickSort

    function quickSort(int[] array, left, right)
        if (left < right)
            int pivot_index = partition(array, left, right)
            quickSort(array, left, pivot_index - 1)     # Organiza os valores à esquerda do pivô
            quickSort(array, pivot_index + 1, right)    # Organiza os valores à direita do pivô


Passo a passo da execução do Quick Sort

    [3, 8, 7, 10, 0, 23, 2, 1, 77] # Array completo
    Primeira chamada de QuickSort(args)
    {
        Left: 0
        Right: 8
        Pivot Index: 3
    }
    -> Resultado:[1, 0, 2, 3, 8, 23, 7, 10, 77]
    
    [1, 0, 2, 3, 8, 23, 7, 10, 77] # Array completo
    Segunda chamada de QuickSort(args)
    {
        [1, 0, 2] # Início
        Esquerda
        {
            Left: 0
            Right: 2
            Pivot Index: 1
        }
        -> Resultado:[0, 1, 2]

        [8, 23, 7, 10, 77] # Início
        Direita
        {
            Left: 4
            Right: 8
            Pivot Index: 5
        }
        -> Resultado:[7, 8, 23, 10, 77]
    } 
    -> Resultado:[0, 1, 2, 3, 7, 8, 23, 10, 77]

    [0, 1, 2, 3, 7, 8, 23, 10, 77] # Array completo
    Última chamada de QuickSort(args)
    {
        //[23, 10, 77] # Início
        Direita
        {
            Left: 6
            Right: 8
            Pivot Index: 7
        }
        ->Resultado[10, 23, 77] 
    }
    -> ResultadoFinal:[0, 1, 2, 7, 8, 10, 23, 77]

