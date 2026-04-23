# Contributing to The Algorithm Hub

Thanks for your interest in contributing — this project grows because of contributors like you.

## How to contribute

1. Fork the repository.
2. Create a branch: `git checkout -b feat/<algorithm>-<language>`.
3. Add your implementation in a clear, self-contained file or folder. Prefer the naming pattern `<algorithm>.<lang>` or a folder named after the algorithm with language-specific files inside.
4. Include at the top of your file:
   - A short description of what the algorithm does.
   - Expected input and output (example if appropriate).
   - Time and space complexity.
   - A minimal usage example or test (small `main` or example call).
5. Run and verify your example locally.
6. Commit with a clear message and open a Pull Request describing what you added and why.

## PR checklist

- [ ] My code follows the repository conventions and is readable.
- [ ] I added or updated a small example or test for the implementation.
- [ ] I included complexity notes and any assumptions about inputs.
- [ ] I did not commit build artifacts or compiled binaries.
- [ ] The LICENSE file is present (MIT) and my contribution is compatible with it.

## Code style

- Keep implementations clear and commented; prefer clarity over cleverness.
- Use consistent naming for variables and functions.
- Add comments for non-trivial steps.

## Tests and examples

- Small inline examples are preferred for single-file algorithms.
- If adding multiple files, include a short `README.md` inside the algorithm folder with build/run instructions.

## Choosing a license and attribution

By contributing you agree your contribution will be licensed under the repository's MIT License. If you need a different license for a large contribution, open an issue to discuss it first.

## Code of Conduct

Be respectful and constructive in PRs and issues. Open-source collaboration succeeds when people are kind and helpful.

---

Thank you for helping make this hub great — fork, add algorithms, and send PRs!
