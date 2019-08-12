from Grafo import Grafo
import copy

class DFS:
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
    
    def buscaProfundidade(self):
        visitado = []
        stack = [0]
        
        g = Grafo(self.estadoInicial)
        
        while stack:
            vertice = stack.pop()
            g.expandir(vertice)

            numFilhos = copy.deepcopy(len(g.getListaAdjacencia()[vertice]))
            custoFilhos = {}
            custoFilhos[0] = []
            custoFilhos[0].append(10000)

            if vertice == 0:
                for i in range(numFilhos):
                    custoFilhos[g.getListaAdjacencia()[vertice][i]] = []
                    custoFilhos[g.getListaAdjacencia()[vertice][i]].append(g.getCusto()[g.getListaAdjacencia()[vertice][i]])
            else:
                for i in range(1,numFilhos):
                    custoFilhos[g.getListaAdjacencia()[vertice][i]] = []
                    custoFilhos[g.getListaAdjacencia()[vertice][i]].append(g.getCusto()[g.getListaAdjacencia()[vertice][i]]) 

            for filho in g.getListaAdjacencia()[vertice]:
                if filho not in visitado:
                    if filho == min(custoFilhos, key=custoFilhos.get):
                        stack.append(filho)

            if self.testeSolucao(g.getPuzzleStore()[vertice]) == True:
                print("Solução Encontrada")
                print(self.acoes)
                break

            self.acoes.append(g.getDirecao()[filho])
            visitado.append(vertice)