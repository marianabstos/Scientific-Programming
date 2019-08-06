import copy

class SubidaEncosta:
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
        
    def subidaEncosta(self):
        visita = [0]
        
        g = Grafo(self.estadoInicial)
        
        while visita:
            vertice = copy.deepcopy(visita.pop())
            g.expandir(vertice)

            for filho in g.getListaAdjacencia()[vertice]:
                if g.getCusto()[vertice] > g.getCusto()[filho]:
                    self.acoes.append(g.getDirecao()[filho])
                    visita.append(filho)

                if self.testeSolucao(g.getPuzzleStore()[vertice]) == True:
                    print("Solução Encontrada")
                    print(self.acoes)
                    break  