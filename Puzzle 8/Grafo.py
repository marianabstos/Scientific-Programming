from random import random
from Puzzle import Puzzle

class Grafo:
    def __init__(self,puzzle):
        self.listaAdjacencia = {} #lista de adjacencia do grafo
        self.listaAdjacencia[0] = [] #inicializando lista de adjacencia
        self.puzzleStore = [] #lista utilizada para guardar cada combinação gerada do quebra-cabeça
        self.puzzleStore.append(puzzle) #inicializando puzzleStore
        self.ultimoVertice = None #variavel utilizada para saber o númere de vertices do grafo
        self.direcao = [] #lista de todas as direções do grafo
        self.direcao.append(None) #inicializando lista de direções
        self.custo = [] #lista de custo das arestas do grafo
        self.custo.append(10000) #Inicilizando o custo
    
    def getListaAdjacencia(self):
        return self.listaAdjacencia
    
    def getPuzzleStore(self):
        return self.puzzleStore
    
    def getDirecao(self):
        return self.direcao
    
    def getCusto(self):
        return self.custo
    
    #Função para calculo da heurística do grafo utilizando distância de Manhattan
    def distanciaManhattan(self, puzzleAtual):
        distMan = 0
        for i,item in enumerate(puzzleAtual):
            prev_row,prev_col = int(i/ 3) , i % 3
            goal_row,goal_col = int(item /3),item % 3
            distMan += abs(prev_row-goal_row) + abs(prev_col - goal_col)
        return distMan/random()
    
    #Função que verifica as condições para expandir o grafo
    def expandir(self, vertice):
        p = Puzzle(self.puzzleStore[vertice])
        p.movimento()

        if vertice == 0:
            for i in range(1,p.getTamanhoVizinhos()+1):
                self.puzzleStore.append(p.getVizinhos()[i-1])
                self.direcao.append(p.getDirecoes()[i-1])
                self.custo.append(self.distanciaManhattan(p.getVizinhos()[i-1]))
                self.listaAdjacencia[vertice].append(i)
                self.listaAdjacencia[i] = []
                self.listaAdjacencia[i].append(vertice)
                self.ultimoVertice = i

        else:
            for i in range(1,p.getTamanhoVizinhos()+1):
                self.puzzleStore.append(p.getVizinhos()[i-1])
                self.direcao.append(p.getDirecoes()[i-1])
                self.custo.append(self.distanciaManhattan(p.getVizinhos()[i-1]))
                self.listaAdjacencia[vertice].append(i+self.ultimoVertice)
                self.listaAdjacencia[i+self.ultimoVertice] = []
                self.listaAdjacencia[i+self.ultimoVertice].append(vertice)

            self.ultimoVertice = self.ultimoVertice + i