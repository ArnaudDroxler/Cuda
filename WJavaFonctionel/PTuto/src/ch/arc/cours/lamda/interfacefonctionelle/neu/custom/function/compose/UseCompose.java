
package ch.arc.cours.lamda.interfacefonctionelle.neu.custom.function.compose;

public class UseCompose
	{

	/*------------------------------------------------------------------*\
	|*							Methodes Public							*|
	\*------------------------------------------------------------------*/

	public static void main(String[] args)
		{
		main();
		}

	public static void main()
		{
		System.out.println("Compose");

		useComposition3();
		}

	/*------------------------------------------------------------------*\
	|*							Methodes Private						*|
	\*------------------------------------------------------------------*/


	/**
	 * x -> x*x+1
	 *
	 * h(x)= x+1
	 * g(x)= x*x
	 * (g o h) (x)= h(g(x))
	 *
	 * lamda
	 */
	private static void useComposition3()
		{
		System.out.println(FunctionCompose.composition3(x->x*2.0,x->x+1.0).value(2));
		}

	/*------------------------------*\
	|*				Tools			*|
	\*------------------------------*/


	}
