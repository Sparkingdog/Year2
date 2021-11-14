fh = open("test.txt", "w")
a = [("a", "200"), ("v", "100")]
fh.writelines(("Abcde\n12345\n"))
fh.writelines(f"{a}\nend...")
fh.close()
