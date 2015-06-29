// Generated from Fabula.g4 by ANTLR 4.5
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class FabulaParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.5", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, STRING=6, CHOICE=7, ARROW=8, GOTO=9, 
		LINECOMMENT=10, BLOCKCOMMENT=11, IDENTIFIER=12, WHITESPACE=13;
	public static final int
		RULE_prog = 0, RULE_sectionContent = 1, RULE_section = 2, RULE_scene = 3, 
		RULE_sceneContent = 4, RULE_choicelist = 5, RULE_choice = 6, RULE_choicerhs = 7, 
		RULE_sceneLocation = 8;
	public static final String[] ruleNames = {
		"prog", "sectionContent", "section", "scene", "sceneContent", "choicelist", 
		"choice", "choicerhs", "sceneLocation"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'['", "']'", "'scene'", "'{'", "'}'", null, "'choice'", "'->'", 
		"'goto'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, null, null, "STRING", "CHOICE", "ARROW", "GOTO", 
		"LINECOMMENT", "BLOCKCOMMENT", "IDENTIFIER", "WHITESPACE"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Fabula.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public FabulaParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class ProgContext extends ParserRuleContext {
		public SectionContentContext sectionContent() {
			return getRuleContext(SectionContentContext.class,0);
		}
		public TerminalNode EOF() { return getToken(FabulaParser.EOF, 0); }
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).enterProg(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).exitProg(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FabulaVisitor ) return ((FabulaVisitor<? extends T>)visitor).visitProg(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_prog);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(18);
			sectionContent();
			setState(19);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SectionContentContext extends ParserRuleContext {
		public List<SectionContext> section() {
			return getRuleContexts(SectionContext.class);
		}
		public SectionContext section(int i) {
			return getRuleContext(SectionContext.class,i);
		}
		public List<SceneContext> scene() {
			return getRuleContexts(SceneContext.class);
		}
		public SceneContext scene(int i) {
			return getRuleContext(SceneContext.class,i);
		}
		public SectionContentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sectionContent; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).enterSectionContent(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).exitSectionContent(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FabulaVisitor ) return ((FabulaVisitor<? extends T>)visitor).visitSectionContent(this);
			else return visitor.visitChildren(this);
		}
	}

	public final SectionContentContext sectionContent() throws RecognitionException {
		SectionContentContext _localctx = new SectionContentContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_sectionContent);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(25);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__2 || _la==IDENTIFIER) {
				{
				setState(23);
				switch (_input.LA(1)) {
				case IDENTIFIER:
					{
					setState(21);
					section();
					}
					break;
				case T__2:
					{
					setState(22);
					scene();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(27);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SectionContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(FabulaParser.IDENTIFIER, 0); }
		public SectionContentContext sectionContent() {
			return getRuleContext(SectionContentContext.class,0);
		}
		public SectionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_section; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).enterSection(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).exitSection(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FabulaVisitor ) return ((FabulaVisitor<? extends T>)visitor).visitSection(this);
			else return visitor.visitChildren(this);
		}
	}

	public final SectionContext section() throws RecognitionException {
		SectionContext _localctx = new SectionContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_section);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(28);
			match(IDENTIFIER);
			setState(29);
			match(T__0);
			setState(30);
			sectionContent();
			setState(31);
			match(T__1);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SceneContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(FabulaParser.IDENTIFIER, 0); }
		public List<TerminalNode> STRING() { return getTokens(FabulaParser.STRING); }
		public TerminalNode STRING(int i) {
			return getToken(FabulaParser.STRING, i);
		}
		public ChoicelistContext choicelist() {
			return getRuleContext(ChoicelistContext.class,0);
		}
		public SceneContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_scene; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).enterScene(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).exitScene(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FabulaVisitor ) return ((FabulaVisitor<? extends T>)visitor).visitScene(this);
			else return visitor.visitChildren(this);
		}
	}

	public final SceneContext scene() throws RecognitionException {
		SceneContext _localctx = new SceneContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_scene);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(33);
			match(T__2);
			setState(34);
			match(IDENTIFIER);
			setState(35);
			match(T__3);
			setState(39);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==STRING) {
				{
				{
				setState(36);
				match(STRING);
				}
				}
				setState(41);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(43);
			_la = _input.LA(1);
			if (_la==CHOICE) {
				{
				setState(42);
				choicelist();
				}
			}

			setState(45);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SceneContentContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(FabulaParser.IDENTIFIER, 0); }
		public SceneContentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sceneContent; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).enterSceneContent(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).exitSceneContent(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FabulaVisitor ) return ((FabulaVisitor<? extends T>)visitor).visitSceneContent(this);
			else return visitor.visitChildren(this);
		}
	}

	public final SceneContentContext sceneContent() throws RecognitionException {
		SceneContentContext _localctx = new SceneContentContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_sceneContent);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(47);
			match(IDENTIFIER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ChoicelistContext extends ParserRuleContext {
		public List<ChoiceContext> choice() {
			return getRuleContexts(ChoiceContext.class);
		}
		public ChoiceContext choice(int i) {
			return getRuleContext(ChoiceContext.class,i);
		}
		public ChoicelistContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_choicelist; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).enterChoicelist(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).exitChoicelist(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FabulaVisitor ) return ((FabulaVisitor<? extends T>)visitor).visitChoicelist(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ChoicelistContext choicelist() throws RecognitionException {
		ChoicelistContext _localctx = new ChoicelistContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_choicelist);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(50); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(49);
				choice();
				}
				}
				setState(52); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==CHOICE );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ChoiceContext extends ParserRuleContext {
		public TerminalNode CHOICE() { return getToken(FabulaParser.CHOICE, 0); }
		public TerminalNode STRING() { return getToken(FabulaParser.STRING, 0); }
		public ChoicerhsContext choicerhs() {
			return getRuleContext(ChoicerhsContext.class,0);
		}
		public ChoiceContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_choice; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).enterChoice(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).exitChoice(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FabulaVisitor ) return ((FabulaVisitor<? extends T>)visitor).visitChoice(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ChoiceContext choice() throws RecognitionException {
		ChoiceContext _localctx = new ChoiceContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_choice);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(54);
			match(CHOICE);
			setState(55);
			match(STRING);
			setState(61);
			switch (_input.LA(1)) {
			case STRING:
			case GOTO:
				{
				{
				setState(56);
				choicerhs();
				}
				}
				break;
			case T__3:
				{
				setState(57);
				match(T__3);
				setState(58);
				choicerhs();
				setState(59);
				match(T__4);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ChoicerhsContext extends ParserRuleContext {
		public TerminalNode GOTO() { return getToken(FabulaParser.GOTO, 0); }
		public SceneLocationContext sceneLocation() {
			return getRuleContext(SceneLocationContext.class,0);
		}
		public TerminalNode STRING() { return getToken(FabulaParser.STRING, 0); }
		public ChoicerhsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_choicerhs; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).enterChoicerhs(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).exitChoicerhs(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FabulaVisitor ) return ((FabulaVisitor<? extends T>)visitor).visitChoicerhs(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ChoicerhsContext choicerhs() throws RecognitionException {
		ChoicerhsContext _localctx = new ChoicerhsContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_choicerhs);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(64);
			_la = _input.LA(1);
			if (_la==STRING) {
				{
				setState(63);
				match(STRING);
				}
			}

			setState(66);
			match(GOTO);
			setState(67);
			sceneLocation();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SceneLocationContext extends ParserRuleContext {
		public List<TerminalNode> IDENTIFIER() { return getTokens(FabulaParser.IDENTIFIER); }
		public TerminalNode IDENTIFIER(int i) {
			return getToken(FabulaParser.IDENTIFIER, i);
		}
		public List<TerminalNode> ARROW() { return getTokens(FabulaParser.ARROW); }
		public TerminalNode ARROW(int i) {
			return getToken(FabulaParser.ARROW, i);
		}
		public SceneLocationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sceneLocation; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).enterSceneLocation(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof FabulaListener ) ((FabulaListener)listener).exitSceneLocation(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof FabulaVisitor ) return ((FabulaVisitor<? extends T>)visitor).visitSceneLocation(this);
			else return visitor.visitChildren(this);
		}
	}

	public final SceneLocationContext sceneLocation() throws RecognitionException {
		SceneLocationContext _localctx = new SceneLocationContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_sceneLocation);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(69);
			match(IDENTIFIER);
			setState(74);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==ARROW) {
				{
				{
				setState(70);
				match(ARROW);
				setState(71);
				match(IDENTIFIER);
				}
				}
				setState(76);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3\17P\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\3\2\3\2\3\2"+
		"\3\3\3\3\7\3\32\n\3\f\3\16\3\35\13\3\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3"+
		"\5\7\5(\n\5\f\5\16\5+\13\5\3\5\5\5.\n\5\3\5\3\5\3\6\3\6\3\7\6\7\65\n\7"+
		"\r\7\16\7\66\3\b\3\b\3\b\3\b\3\b\3\b\3\b\5\b@\n\b\3\t\5\tC\n\t\3\t\3\t"+
		"\3\t\3\n\3\n\3\n\7\nK\n\n\f\n\16\nN\13\n\3\n\2\2\13\2\4\6\b\n\f\16\20"+
		"\22\2\2N\2\24\3\2\2\2\4\33\3\2\2\2\6\36\3\2\2\2\b#\3\2\2\2\n\61\3\2\2"+
		"\2\f\64\3\2\2\2\168\3\2\2\2\20B\3\2\2\2\22G\3\2\2\2\24\25\5\4\3\2\25\26"+
		"\7\2\2\3\26\3\3\2\2\2\27\32\5\6\4\2\30\32\5\b\5\2\31\27\3\2\2\2\31\30"+
		"\3\2\2\2\32\35\3\2\2\2\33\31\3\2\2\2\33\34\3\2\2\2\34\5\3\2\2\2\35\33"+
		"\3\2\2\2\36\37\7\16\2\2\37 \7\3\2\2 !\5\4\3\2!\"\7\4\2\2\"\7\3\2\2\2#"+
		"$\7\5\2\2$%\7\16\2\2%)\7\6\2\2&(\7\b\2\2\'&\3\2\2\2(+\3\2\2\2)\'\3\2\2"+
		"\2)*\3\2\2\2*-\3\2\2\2+)\3\2\2\2,.\5\f\7\2-,\3\2\2\2-.\3\2\2\2./\3\2\2"+
		"\2/\60\7\7\2\2\60\t\3\2\2\2\61\62\7\16\2\2\62\13\3\2\2\2\63\65\5\16\b"+
		"\2\64\63\3\2\2\2\65\66\3\2\2\2\66\64\3\2\2\2\66\67\3\2\2\2\67\r\3\2\2"+
		"\289\7\t\2\29?\7\b\2\2:@\5\20\t\2;<\7\6\2\2<=\5\20\t\2=>\7\7\2\2>@\3\2"+
		"\2\2?:\3\2\2\2?;\3\2\2\2@\17\3\2\2\2AC\7\b\2\2BA\3\2\2\2BC\3\2\2\2CD\3"+
		"\2\2\2DE\7\13\2\2EF\5\22\n\2F\21\3\2\2\2GL\7\16\2\2HI\7\n\2\2IK\7\16\2"+
		"\2JH\3\2\2\2KN\3\2\2\2LJ\3\2\2\2LM\3\2\2\2M\23\3\2\2\2NL\3\2\2\2\n\31"+
		"\33)-\66?BL";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}