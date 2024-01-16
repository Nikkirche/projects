// Generated from Input.g4 by ANTLR 4.13.1

package parser;

import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link InputParser}.
 */
public interface InputListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link InputParser#gramm}.
	 * @param ctx the parse tree
	 */
	void enterGramm(InputParser.GrammContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#gramm}.
	 * @param ctx the parse tree
	 */
	void exitGramm(InputParser.GrammContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#head}.
	 * @param ctx the parse tree
	 */
	void enterHead(InputParser.HeadContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#head}.
	 * @param ctx the parse tree
	 */
	void exitHead(InputParser.HeadContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#rule}.
	 * @param ctx the parse tree
	 */
	void enterRule(InputParser.RuleContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#rule}.
	 * @param ctx the parse tree
	 */
	void exitRule(InputParser.RuleContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#noterminal_rule}.
	 * @param ctx the parse tree
	 */
	void enterNoterminal_rule(InputParser.Noterminal_ruleContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#noterminal_rule}.
	 * @param ctx the parse tree
	 */
	void exitNoterminal_rule(InputParser.Noterminal_ruleContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#rule_inn}.
	 * @param ctx the parse tree
	 */
	void enterRule_inn(InputParser.Rule_innContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#rule_inn}.
	 * @param ctx the parse tree
	 */
	void exitRule_inn(InputParser.Rule_innContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#code}.
	 * @param ctx the parse tree
	 */
	void enterCode(InputParser.CodeContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#code}.
	 * @param ctx the parse tree
	 */
	void exitCode(InputParser.CodeContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#rdec}.
	 * @param ctx the parse tree
	 */
	void enterRdec(InputParser.RdecContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#rdec}.
	 * @param ctx the parse tree
	 */
	void exitRdec(InputParser.RdecContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#redecl}.
	 * @param ctx the parse tree
	 */
	void enterRedecl(InputParser.RedeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#redecl}.
	 * @param ctx the parse tree
	 */
	void exitRedecl(InputParser.RedeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#indecl}.
	 * @param ctx the parse tree
	 */
	void enterIndecl(InputParser.IndeclContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#indecl}.
	 * @param ctx the parse tree
	 */
	void exitIndecl(InputParser.IndeclContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#ruleb}.
	 * @param ctx the parse tree
	 */
	void enterRuleb(InputParser.RulebContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#ruleb}.
	 * @param ctx the parse tree
	 */
	void exitRuleb(InputParser.RulebContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#rule_body}.
	 * @param ctx the parse tree
	 */
	void enterRule_body(InputParser.Rule_bodyContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#rule_body}.
	 * @param ctx the parse tree
	 */
	void exitRule_body(InputParser.Rule_bodyContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#inh}.
	 * @param ctx the parse tree
	 */
	void enterInh(InputParser.InhContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#inh}.
	 * @param ctx the parse tree
	 */
	void exitInh(InputParser.InhContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#terminal_rule}.
	 * @param ctx the parse tree
	 */
	void enterTerminal_rule(InputParser.Terminal_ruleContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#terminal_rule}.
	 * @param ctx the parse tree
	 */
	void exitTerminal_rule(InputParser.Terminal_ruleContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#terminal_rule_inn}.
	 * @param ctx the parse tree
	 */
	void enterTerminal_rule_inn(InputParser.Terminal_rule_innContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#terminal_rule_inn}.
	 * @param ctx the parse tree
	 */
	void exitTerminal_rule_inn(InputParser.Terminal_rule_innContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#terminal}.
	 * @param ctx the parse tree
	 */
	void enterTerminal(InputParser.TerminalContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#terminal}.
	 * @param ctx the parse tree
	 */
	void exitTerminal(InputParser.TerminalContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#noterminal}.
	 * @param ctx the parse tree
	 */
	void enterNoterminal(InputParser.NoterminalContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#noterminal}.
	 * @param ctx the parse tree
	 */
	void exitNoterminal(InputParser.NoterminalContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#ident}.
	 * @param ctx the parse tree
	 */
	void enterIdent(InputParser.IdentContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#ident}.
	 * @param ctx the parse tree
	 */
	void exitIdent(InputParser.IdentContext ctx);
	/**
	 * Enter a parse tree produced by {@link InputParser#epsilon}.
	 * @param ctx the parse tree
	 */
	void enterEpsilon(InputParser.EpsilonContext ctx);
	/**
	 * Exit a parse tree produced by {@link InputParser#epsilon}.
	 * @param ctx the parse tree
	 */
	void exitEpsilon(InputParser.EpsilonContext ctx);
}