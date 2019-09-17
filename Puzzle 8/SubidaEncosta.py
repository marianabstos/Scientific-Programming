from Grafo import Grafo
import copy

class SubidaEncosta:
    def __init__(self, estadoInicial, objetivo):
        self.estadoInicial = estadoInicial #vertice inicial da Subida Encosta
        self.objetivo = objetivo #Vertice objetivo da Subida Encosta
        self.acoes = [] #Lista de ações tomada pela Subida Encosta
        
    def getAcoes(self):
        return self.acoes
    
    #Função que verifica se o vértice é a solução do quebra-cabeça
    def testeSolucao(self, estadoAtual):
        if self.objetivo == estadoAtual:
            return True
        else:
            return False
    
    #Função onde ocorre a Subida de Encosta
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