// Generated from Fabula.g4 by ANTLR 4.5
import org.antlr.v4.runtime.misc.NotNull;
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link FabulaParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface FabulaVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link FabulaParser#prog}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProg(FabulaParser.ProgContext ctx);
	/**
	 * Visit a parse tree produced by {@link FabulaParser#sectionContent}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSectionContent(FabulaParser.SectionContentContext ctx);
	/**
	 * Visit a parse tree produced by {@link FabulaParser#section}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSection(FabulaParser.SectionContext ctx);
	/**
	 * Visit a parse tree produced by {@link FabulaParser#scene}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitScene(FabulaParser.SceneContext ctx);
	/**
	 * Visit a parse tree produced by {@link FabulaParser#sceneContent}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSceneContent(FabulaParser.SceneContentContext ctx);
	/**
	 * Visit a parse tree produced by {@link FabulaParser#choicelist}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitChoicelist(FabulaParser.ChoicelistContext ctx);
	/**
	 * Visit a parse tree produced by {@link FabulaParser#choice}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitChoice(FabulaParser.ChoiceContext ctx);
	/**
	 * Visit a parse tree produced by {@link FabulaParser#choicerhs}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitChoicerhs(FabulaParser.ChoicerhsContext ctx);
	/**
	 * Visit a parse tree produced by {@link FabulaParser#sceneLocation}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSceneLocation(FabulaParser.SceneLocationContext ctx);
}