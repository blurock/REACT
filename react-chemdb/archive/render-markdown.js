(async function renderArchiveMarkdown() {
  const targets = Array.from(document.querySelectorAll("[data-markdown-src]"));
  if (targets.length === 0) return;

  const cache = new Map();

  async function loadSource(source) {
    if (cache.has(source)) return cache.get(source);
    const response = await fetch(source, { cache: "no-store" });
    if (!response.ok) {
      throw new Error("Unable to load markdown source");
    }
    const markdown = await response.text();
    cache.set(source, markdown);
    return markdown;
  }

  for (const target of targets) {
    const source = target.getAttribute("data-markdown-src");
    if (!source) continue;

    try {
      const markdown = await loadSource(source);
      if (window.marked && typeof window.marked.parse === "function") {
        target.innerHTML = window.marked.parse(markdown, {
          breaks: true,
          gfm: true
        });
      } else {
        target.textContent = markdown;
      }
    } catch (err) {
      target.innerHTML = "<p>Could not render archive markdown for this section.</p>";
    }
  }
})();
