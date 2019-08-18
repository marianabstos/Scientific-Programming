def funcao_a(x):
    return x*x

def derivada_funcao_a(x):
    return 2*x

def funcao_b(x):
    return ((x*x*x) - (2*(x*x)) + 2)

def derivada_funcao_b(x):
    return ((3*(x*x)) - (4*x))


from decimal import Decimal
def newton_raphson_a(num, beta, max):
    x = []
    x.append(num)
    f = []
    f.append(round(funcao_a(x[0]),2))
    
    i=0

    while((f[i] > 0)):
            x.append(x[i] - (beta*f[i]*(1/derivada_funcao_a(x[i]))))
            i+=1
            f.append(round(funcao_a(x[i]),2))
            
            if i == max:
                break

    print("f({0}) = {1:.3f}".format(i-1,f[i-1]))
    print("x{0} = {1:.3f}".format(i-1,x[i-1]))
    print("Taxa aprendizado = {0:.1f}".format(beta))
    
    
def newton_raphson_b(num, beta, max):
    x = []
    x.append(num)
    f = []
    f.append(float(round(funcao_b(x[0]),2)))
    
    i=0
    while((f[i] > 0)):
        x.append(x[i] - (beta*f[i]*(1/derivada_funcao_b(x[i]))))
        i+=1
        f.append(float(round(funcao_b(x[i]),2)))
        
        if i == max:
            break
        
    print("f({0}) = {1:.3f}".format(i-1,f[i-1]))
    print("x{0} = {1:.3f}".format(i-1,x[i-1]))
    print("Taxa aprendizado = {0:.1f}".format(beta))
    
    
def gradient_a(num,beta,max):
    x = []
    x.append(num)
    f = []
    f.append(round(funcao_a(x[0]),2))
    
    i=0
    
    while((f[i] > 0)):
        x.append(x[i] - ((beta)*(derivada_funcao_a(x[i]))))
        
        i+=1
    
        f.append(round(derivada_funcao_a(x[i]),2))
        
        if i == max:
            break
    
    print("f'({0}) = {1:.3f}".format(i-1,f[i-1]))
    print("x{0} = {1:.3f}".format(i-1,x[i-1]))
    print("Taxa aprendizado = {0:.1f}".format(beta))
    
def gradient_b(num,beta,max):
    x = []
    x.append(num)
    f = []
    f.append(round(funcao_b(x[0]),2))
    
    i=0
    
    while((f[i] > 0)):
        x.append(x[i] - ((beta)*(derivada_funcao_b(x[i]))))
        i+=1
        f.append(round(derivada_funcao_b(x[i]),2))
        
        if i == max:
            break
    
    print("f'({0}) = {1:.3f}".format(i-1,f[i-1]))
    print("x{0} = {1:.3f}".format(i-1,x[i-1]))
    print("Taxa aprendizado = {0:.1f}".format(beta))