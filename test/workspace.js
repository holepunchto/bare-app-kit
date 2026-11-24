const { test } = require('bare-tap')
const { Image, Workspace } = require('..')

test('rejects paths and URLs with a NUL', (t) => {
  const path = '/Applications/Missing.app\0.txt'

  t.throws(() => Workspace.openURL('https://attacker.example\0.trusted.example'), TypeError)
  t.throws(() => Workspace.openFile(path), TypeError)
  t.throws(() => Workspace.openApplication(path), TypeError)
  t.throws(() => Workspace.selectFile(path), TypeError)
  t.throws(() => Workspace.isFilePackage(path), TypeError)
  t.throws(() => Image.withContentsOfFile(path), TypeError)
})
