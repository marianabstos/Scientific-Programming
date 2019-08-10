from Grafo import Grafo
from random import random
import copy

class Aestrela:
    def __init__(self, estadoInicial, objetivo):
        self.estadoInicial = estadoInicial
        self.objetivo = objetivo
        self.acoes = []
        
    def getAcoes(self):
        return self.acoes
    
    def testeSolucao(self, estadoAtual):
        if self.objetivo == estadoAtual:
            return True
        else:
            return False
        
    def buscaAestrela(self):
        visita = [0]
        heuristica = {}
        
        g = Grafo(self.estadoInicial)
        
        while visita:
            vertice = copy.deepcopy(visita.pop())
            g.expandir(vertice)

            for filho in g.getListaAdjacencia()[vertice]:
                heuristica[filho] = []
                heuristica[filho].append((g.getCusto()[vertice] + g.getCusto()[filho]) + g.getCusto()[filho]*random())
                
            verticeMenorCusto = min(heuristica, key=heuristica.get)
                
            if self.testeSolucao(g.getPuzzleStore()[vertice]) == True:
                print("Solução Encontrada")
                print(self.acoes)
                break  
                
            if verticeMenorCusto not in visita:
                self.acoes.append(g.getDirecao()[verticeMenorCusto])
                visita.append(verticeMenorCusto)