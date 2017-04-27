
package ch.arc.cours.lamda.interfacefonctionelle.neu.existant.function;

import java.util.List;

import org.junit.Assert;

import ch.arc.cours.lamda.interfacefonctionelle.neu.existant.function.tools.Maison;
import ch.arc.cours.lamda.interfacefonctionelle.neu.existant.function.tools.MaisonTools;

public class UseFunctionFilterMapReduce
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
		System.out.println("filter map Reduce : Predicate Function binaryOperator ");

		filterMapReduce();
		}


	/*------------------------------------------------------------------*\
	|*							Methodes Private						*|
	\*------------------------------------------------------------------*/

	private static void filterMapReduce()
		{
		int n = 4;
		List<Maison> list = MaisonTools.create(n);

		int sum3 = version3(list);

		System.out.println(list);

		check(list, sum3);
		}
	/**
	 * somme des prix des maisons dont nbPiece>20
	 *
	 * lamda
	 */
	private static int version3(List<Maison> list)
		{
		return MaisonManipulator.filterMapReduce(list, m->m.getNbPiece()>20, m->m.getPrix(), (i,j)->i+j, 0);
		}

	/*------------------------------*\
	|*				Tools			*|
	\*------------------------------*/

	private static void check(List<Maison> list, int sum)
		{
		System.out.println("sum prix = " + sum);

		Assert.assertTrue(sum == 7);
		}

	}