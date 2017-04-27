
package ch.arc.cours.lamda.interfacefonctionelle.neu.custom.function.compose;

import ch.arc.cours.lamda.interfacefonctionelle.neu.custom.function.Function_I;

public class FunctionCompose
	{

	/*------------------------------------------------------------------*\
	|*							Methodes Public							*|
	\*------------------------------------------------------------------*/


	/**
	 * (h 0 g)(x) = h(g(x))
	 *
	 * lamda
	 */
	public static Function_I composition3(Function_I h, Function_I g)
		{
		return x-> h.value(g.value(x));
		}

	/*------------------------------------------------------------------*\
	|*							Methodes Private						*|
	\*------------------------------------------------------------------*/

	}
