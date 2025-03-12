horaAdmin = 22.00
horaProd = 12.00
taxaInss = 0.07
taxaIr = 0.12
planoDeSaude = 20.00
MaxFuncionarios = 5

funcionarios = []

def calcularSalarioBase(departamento, horasTrabalhadas):
    valorHora = horaAdmin if departamento == 1 else horaProd
    return horasTrabalhadas * valorHora

def calcularHoraExtra(departamento, horasTrabalhadas):
    if horasTrabalhadas <= 40:
        return 0.0
    valor_hora = horaAdmin if departamento == 1 else horaProd
    return valor_hora * 2 * (horasTrabalhadas - 40)

def calcularInsalubridade(departamento, salarioBase):
    return salarioBase * 0.15 if departamento == 2 else 0.0

def calcularbonificacao(departamento, horasTrabalhadas, salarioBase):
    if departamento != 1:
        return 0.0
    if horasTrabalhadas > 40:
        return salarioBase * 0.10
    elif horasTrabalhadas > 30:
        return salarioBase * 0.05
    elif horasTrabalhadas > 20:
        return salarioBase * 0.03
    return 0.0

def calcularSalarioBruto(salarioBase, horaExtra, insalubridade, bonificacao):
    return salarioBase + horaExtra + insalubridade + bonificacao

def calcularInss(salarioBruto):
    return salarioBruto * taxaInss

def calcularImpostoDeRenda(salarioBruto):
    return salarioBruto * taxaIr

def calcularSalarioLiquido(salarioBruto, inss, impostoDeRenda):
    return salarioBruto - inss - impostoDeRenda

def exibirFolhaDePagamento(funcionarios):
    cabecalho = (
        "Ordem    Nome           Salário Base   Hora Extra  Insalubridade   Bonificação  INSS      IR        Plano Saúde  Salário Líquido\n"
        "----------------------------------------------------------------------------------------------------------------------------"
    )
    print(cabecalho)

    for i, func in enumerate(funcionarios):
        linha = (
            f"{i + 1:<5}  {func['nome']:<15} {func['salario_base']:<15.2f} {func['hora_extra']:<10.2f} "
            f"{func['insalubridade']:<15.2f} {func['bonificacao']:<12.2f} {func['inss']:<10.2f} "
            f"{func['ir']:<10.2f} {planoDeSaude:<15.2f} {func['salario_liquido']:<15.2f}"
        )
        print(linha)

for i in range(MaxFuncionarios):
    print(f"Funcionario {i + 1}")
    nome = input("Nome: ")
    departamento = int(input("Departamento (Digite 1 para Administração ou 2 para Produção)"))
    horasTrabalhadas = float(input("Horas trabalhadas: "))

    salarioBase = calcularSalarioBase(departamento, horasTrabalhadas)
    horaExtra = calcularHoraExtra(departamento, horasTrabalhadas)
    insalubridade = calcularInsalubridade(departamento, salarioBase)
    bonificacao = calcularbonificacao(departamento, horasTrabalhadas, salarioBase)
    salarioBruto = calcularSalarioBruto(salarioBase, horaExtra, insalubridade, bonificacao)
    inss = calcularInss(salarioBruto)
    impostoDeRenda = calcularImpostoDeRenda(salarioBruto)
    salarioLiquido = calcularSalarioLiquido(salarioBruto, inss, impostoDeRenda)

    funcionario = {
        'nome': nome,
        'departamento': departamento,
        'horas_trabalhadas': horasTrabalhadas,
        'salario_base': salarioBase,
        'hora_extra': horaExtra,
        'insalubridade': insalubridade,
        'bonificacao': bonificacao,
        'salario_bruto': salarioBruto,
        'inss': inss,
        'ir': impostoDeRenda,
        'salario_liquido': salarioLiquido
    }
    funcionarios.append(funcionario)

exibirFolhaDePagamento(funcionarios)