1. O que são sistemas embarcados?  
Sistemas embarcados são combinações de hardware e software projetadas para
aplicações específicas com tarefas predefinidas. Possibilitam a otimização do
projeto reduzindo tamanho, recursos computacionais, custo e consumo energético
em relação a sistemas de propósito geral.

2. O que são sistemas microprocesssados?  
Sistemas microprocessados são aqueles que utilizam em sua arquitetura
microprocessadores.

3. Apresente aplicações de sistemas embarcados:  
	(a) Para a indústria automotiva;  
	Monitorar o consumo de combustível, temperatura e rotações do motor para melhora na eficiência energética através de ações tomadas pela central eletrônica do automóvel.  
	(b) Para eletrodomésticos;  
	Monitorar temperaturas de ambientes para condicioná-los com eficiência; prover interfaces homem-máquina, por exemplo, controle de funções através de *displays* sensíveis ao toque.  
	(c) Para automação industrial.  
	Uso em sistemas de controle de braços robóticos, reproduzindo movimentos de forma precisa.  

4. Cite arquiteturas possíveis e as diferenças entre elas.  
  
  * Microcontroladores: baixa potência, pouco poder de processamento, baixo número de entradas e saídas, pouca memória volátil e não volátil, alto controle sobre a temporização.
  * Microcontroladores com  Processadores de propósito geral (*GPP*): as mesmas vantagens dos microcontroladores aliadas ao maior poder de processamento dos processadores de propósito geral, com a possibilidade de execução de Linux embarcado.
  * DSP (*Digital Signal Processors*): microprocessadores especializados em processamento digital de sinais. Baixo consumo de energia, semelhante aos microcontroladores, mas com maior quantidade de entradas e saídas analógicas.
  * FPGA (*Field-programmable gate array*): execução paralela de algoritmos, implementação de microprocessadores personalizados.
  * ASIC (*Application Specific Integrated Circuit*): circuitos integrados construídos em chips para aplicações específicas possuem a maior possibilidade de redução de consumo energético.
  * SoC (*System on a Chip*) GPP+GPU: maior poder de processamento e fácil integração com interfaces homem-máquina.
  * MPSoC (*multiprocessor system-on-chip*): possui as vantagens combinadas de diversas arquiteturas. Geralmente permite a integração de múltiplos microprocessadotes, FPGAs e microcontroladores em uma solução embarcável integrada.

5. Por que usamos o Raspberry Pi na disciplina, ao invés de outro system-on-chip?  
Grande comunidade de usuários, menor preço comparado aos SoCs igualmente famosos, facilidade de uso, grande disponibilidade de modelos.