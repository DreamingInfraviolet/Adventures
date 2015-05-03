// Generated from Fabula.g4 by ANTLR 4.5
import org.antlr.v4.runtime.misc.NotNull;
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link FabulaParser}.
 */
public interface FabulaListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link FabulaParser#prog}.
	 * @param ctx the parse tree
	 */
	void enterProg(FabulaParser.ProgContext ctx);
	/**
	 * Exit a parse tree produced by {@link FabulaParser#prog}.
	 * @param ctx the parse tree
	 */
	void exitProg(FabulaParser.ProgContext ctx);
	/**
	 * Enter a parse tree produced by {@link FabulaParser#sectionContent}.
	 * @param ctx the parse tree
	 */
	void enterSectionContent(FabulaParser.SectionContentContext ctx);
	/**
	 * Exit a parse tree produced by {@link FabulaParser#sectionContent}.
	 * @param ctx the parse tree
	 */
	void exitSectionContent(FabulaParser.SectionContentContext ctx);
	/**
	 * Enter a parse tree produced by {@link FabulaParser#section}.
	 * @param ctx the parse tree
	 */
	void enterSection(FabulaParser.SectionContext ctx);
	/**
	 * Exit a parse tree produced by {@link FabulaParser#section}.
	 * @param ctx the parse tree
	 */
	void exitSection(FabulaParser.SectionContext ctx);
	/**
	 * Enter a parse tree produced by {@link FabulaParser#scene}.
	 * @param ctx the parse tree
	 */
	void enterScene(FabulaParser.SceneContext ctx);
	/**
	 * Exit a parse tree produced by {@link FabulaParser#scene}.
	 * @param ctx the parse tree
	 */
	void exitScene(FabulaParser.SceneContext ctx);
	/**
	 * Enter a parse tree produced by {@link FabulaParser#sceneContent}.
	 * @param ctx the parse tree
	 */
	void enterSceneContent(FabulaParser.SceneContentContext ctx);
	/**
	 * Exit a parse tree produced by {@link FabulaParser#sceneContent}.
	 * @param ctx the parse tree
	 */
	void exitSceneContent(FabulaParser.SceneContentContext ctx);
	/**
	 * Enter a parse tree produced by {@link FabulaParser#choicelist}.
	 * @param ctx the parse tree
	 */
	void enterChoicelist(FabulaParser.ChoicelistContext ctx);
	/**
	 * Exit a parse tree produced by {@link FabulaParser#choicelist}.
	 * @param ctx the parse tree
	 */
	void exitChoicelist(FabulaParser.ChoicelistContext ctx);
	/**
	 * Enter a parse tree produced by {@link FabulaParser#choice}.
	 * @param ctx the parse tree
	 */
	void enterChoice(FabulaParser.ChoiceContext ctx);
	/**
	 * Exit a parse tree produced by {@link FabulaParser#choice}.
	 * @param ctx the parse tree
	 */
	void exitChoice(FabulaParser.ChoiceContext ctx);
	/**
	 * Enter a parse tree produced by {@link FabulaParser#choicerhs}.
	 * @param ctx the parse tree
	 */
	void enterChoicerhs(FabulaParser.ChoicerhsContext ctx);
	/**
	 * Exit a parse tree produced by {@link FabulaParser#choicerhs}.
	 * @param ctx the parse tree
	 */
	void exitChoicerhs(FabulaParser.ChoicerhsContext ctx);
	/**
	 * Enter a parse tree produced by {@link FabulaParser#sceneLocation}.
	 * @param ctx the parse tree
	 */
	void enterSceneLocation(FabulaParser.SceneLocationContext ctx);
	/**
	 * Exit a parse tree produced by {@link FabulaParser#sceneLocation}.
	 * @param ctx the parse tree
	 */
	void exitSceneLocation(FabulaParser.SceneLocationContext ctx);
}