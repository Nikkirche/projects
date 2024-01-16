plugins {
    kotlin("jvm") version "1.9.0"
    application
    antlr
}

group = "org.example"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

dependencies {
    testImplementation(kotlin("test"))
    antlr("org.antlr:antlr4:4.13.1")
    antlr("org.antlr:antlr4-runtime:4.13.1")

}

tasks.test {
    useJUnitPlatform()
}

kotlin {
    jvmToolchain(8)
}

application {
    mainClass.set("MainKt")
}


tasks.compileKotlin{
    dependsOn(tasks.generateGrammarSource)
}
tasks.compileTestKotlin{
    dependsOn(tasks.generateTestGrammarSource)
}


tasks.compileJava{
    dependsOn(tasks.generateGrammarSource)
}
tasks.compileTestJava{
    dependsOn(tasks.generateTestGrammarSource)
}

tasks.generateGrammarSource{
    arguments.add("-listener")
    outputDirectory = file("src/main/java/parser")
}
