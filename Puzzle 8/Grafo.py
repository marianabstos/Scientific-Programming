from random import random

class Grafo:
    def __init__(self,puzzle):
        self.listaAdjacencia = {}
        self.listaAdjacencia[0] = []
        self.puzzleStore = []
        self.puzzleStore.append(puzzle)
        self.ultimoVertice = None
        self.direcao = []
        self.direcao.append(None)
        self.custo = []
        self.custo.append(10000)
    
    def getListaAdjacencia(self):
        return self.listaAdjacencia
    
    def getPuzzleStore(self):
        return self.puzzleStore
    
    def getDirecao(self):
        return self.direcao
    
    def getCusto(self):
        return self.custo
    
    def distanciaManhattan(self, puzzleAtual):
        distMan = 0
        for i,item in enumerate(puzzleAtual):
            prev_row,prev_col = int(i/ 3) , i % 3
            goal_row,goal_col = int(item /3),item % 3
            distMan += abs(prev_row-goal_row) + abs(prev_col - goal_col)
        return distMan/random()
    
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