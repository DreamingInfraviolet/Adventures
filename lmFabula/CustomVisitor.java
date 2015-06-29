import org.antlr.v4.runtime.tree.TerminalNode;


public class CustomVisitor<T> extends FabulaBaseVisitor<T>
{
	private Section mBase = new Section("base",null); //base, represented by the null location
	private Section mCurrentSection = mBase;
	private Scene mCurrentScene = null;
	private ChoiceList mCurrentChoiceList = null;
	private Choice mCurrentChoice = null;
	
	public CompilationException error = null;

	public CustomVisitor()
	{
	}

	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation returns the result of calling
	 * {@link #visitChildren} on {@code ctx}.</p>
	 */
	@Override public T visitProg(FabulaParser.ProgContext ctx)
	{ 
		return visitChildren(ctx);
	}

	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation returns the result of calling
	 * {@link #visitChildren} on {@code ctx}.</p>
	 */
	@Override public T visitSectionContent(FabulaParser.SectionContentContext ctx)
	{ 
		return visitChildren(ctx);
	}

	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation returns the result of calling
	 * {@link #visitChildren} on {@code ctx}.</p>
	 */
	@Override public T visitSection(FabulaParser.SectionContext ctx)
	{ 
		String name = ctx.IDENTIFIER().getText().toLowerCase();
		Section newSection = new Section(name, mCurrentSection);
		mCurrentSection.addSection(newSection);
		Section lastSection = mCurrentSection;
		mCurrentSection = newSection;
		T out = visitChildren(ctx);
		mCurrentSection = lastSection;
		return out;
	}

	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation returns the result of calling
	 * {@link #visitChildren} on {@code ctx}.</p>
	 */
	@Override public T visitScene(FabulaParser.SceneContext ctx)
	{ 
		//construct scene
		TerminalNode name = ctx.IDENTIFIER();
		Scene scene = new Scene(name.getText().toLowerCase());
		mCurrentSection.addScene(scene);
		
		//backup current scene
		Scene lastScene = mCurrentScene;
		mCurrentScene = scene;
		
		//analyse scene using current scene
		T out = visitChildren(ctx);
		
		//restore current scene
		mCurrentScene = lastScene;
		return out;
	}

	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation returns the result of calling
	 * {@link #visitChildren} on {@code ctx}.</p>
	 */
	@Override public T visitSceneContent(FabulaParser.SceneContentContext ctx)
	{ 
		//initialise strings in scene
		FString[] fStrings = new FString[ctx.STRING().size()];
		for (int i = 0; i < fStrings.length; ++i)
			fStrings[i] = new FString(ctx.STRING().get(i).getText());
		
		//Initialise choice list
		ChoiceList choiceList = new ChoiceList();
		ChoiceList lastChoiceList = mCurrentChoiceList;
		mCurrentChoiceList = choiceList;
		
		//populate choicelist
		T out =  visitChildren(ctx);
		
		//finish up
		mCurrentChoiceList = lastChoiceList;
		
		mCurrentScene.setSceneContent(fStrings, choiceList);
		
		return out;
	}

	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation returns the result of calling
	 * {@link #visitChildren} on {@code ctx}.</p>
	 */
	@Override public T visitChoicelist(FabulaParser.ChoicelistContext ctx)
	{ 
		//visit every choice
		for(int i = 0; i < ctx.choice().size(); ++i)
			visit(ctx.choice().get(i).getRuleContext());
		return null;
	}

	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation returns the result of calling
	 * {@link #visitChildren} on {@code ctx}.</p>
	 */
	@Override public T visitChoice(FabulaParser.ChoiceContext ctx)
	{ 
		Choice choice = new Choice(new FString(ctx.STRING()==null ? "":ctx.STRING().getText()),
								   new FString(ctx.choicerhs().STRING().getText()));
		mCurrentChoiceList.addChoice(choice);
		mCurrentChoice = choice;
		
		//populate scene location
		T out = visitChildren(ctx);
		mCurrentChoice = null;
		return out;
	}

	/**
	 * {@inheritDoc}
	 *
	 * <p>The default implementation returns the result of calling
	 * {@link #visitChildren} on {@code ctx}.</p>
	 * @throws CompilationException 
	 */
	@Override public T visitSceneLocation(FabulaParser.SceneLocationContext ctx)
	{ 
		SectionLocation location = new SectionLocation();
		mCurrentChoice.setSceneLocation(location);
		
		//climb tree and add sections
		
		location.setOrigin(mCurrentSection.getName());
		
		//add any sections
		for(int i = 0; i < ctx.IDENTIFIER().size()-1; ++i)
			location.addLocation(ctx.IDENTIFIER(i).getText().toLowerCase());
		
		location.setScene(ctx.IDENTIFIER(ctx.IDENTIFIER().size()-1).getText().toLowerCase());

	
		return visitChildren(ctx);
	}

}