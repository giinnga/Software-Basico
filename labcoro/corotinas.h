/* tipo do parâmetro para uma corotina */
typedef int CoroParam;

/* corpo de uma corotina */
typedef CoroParam (*CoroBody)(CoroParam param);

/* referencia para uma corotina */
typedef struct coroDescr *CoroP; 

/* 
 * coro_create: cria uma nova corotina
 *
 * Parâmetro: função que implementa o "corpo" da corotina
 * Retorna: referencia para a corotina criada
 */
CoroP coro_create(char *name, CoroBody func);

/*
 * coro_resume: (re)ativa a execução de uma corotina
 *
 * Parâmetros:
 *   - referencia para a corotina a (re)ativar
 *   - parametro para a corotina (parametro inicial ou retorno de coro_yield)
 *
 * Retorna:
 *   o parâmetro passado a coro_yield quando a corotina suspender,
 *   ou o retorno do "corpo" da corotina, quando ela terminar
 */
CoroParam coro_resume(CoroP coro, CoroParam param);

/*
 * coro_yield: suspende a execução de uma corotina, retomando a execução 
 *             do chamador 
 * Parâmetros:
 *   - valor de retorno para o chamador (retorno de coro_resume)
 *
 * Retorna:
 *   o parâmetro passado a coro_resume quando a corotina for reativada
 */
CoroParam coro_yield(CoroParam param);

/*
 * coro_free: libera área usada por corotina
 *
 * Parâmetro: referencia para a corotina
 */
void coro_free(CoroP coro);
